from semantica import *
if_counter = 0
while_counter = 0


def codeGen(tree, file):
    fw = FileWriter(file) 
    fw.openFile()
    table = tabla(tree, False)
    compileCode(tree, table, fw)
    fw.closeFile()
class FileWriter(object):
    def __init__(self, file):
        self.file = file

    def openFile(self):
        self.f = open(self.file, "w+")

    def closeFile(self):
        self.f.close()
    
    def write(self, text, breakLine=True, tab=True):
        if tab: self.f.write("\t")
        self.f.write(text)
        if breakLine: self.f.write("\n")


def compileCode(node, table, fw):
    global if_counter
    global while_counter
    if node[0] is 'declaration_list':
        for child in node[1:]:
            compileCode(child, table, fw)

    elif node[0] is 'function_declaration':    
        returns  = node[1]          
        functionID   = node[2]
        if node[3] != 'void':
            params = node[3][1:]
        else:
            params = 'void'
        fw.write(f"{functionID}:", tab=False)
        compileCode(node[4], table, fw)

    elif node[0] is 'variable_declaration':
        fw.write('li $s0 0')                       
        fw.write('sw $s0,0($sp)')             
        fw.write('addi $sp,$sp,-4')   
    
    elif node[0] is "number":
        fw.write(f"li $a0, {node[1]}") 

    elif node[0] is 'function_call':
        functionId  = node[1]
        params = node[2:] 
        if functionId  == 'input': 
            fw.write("li $v0, 5")     
            fw.write("syscall")       
            fw.write("move $a0, $v0")
        elif functionId  == 'output':
            compileCode( params[0], table, fw ) 
            fw.write("li $v0, 1")     
            fw.write("syscall")       
            fw.write("move $t8, $a0")     
            fw.write("addi $a0, $0, 0xA") 
            fw.write("addi $v0, $0, 0xB") 
            fw.write("syscall")           
            fw.write("move $a0, $t8")    
        else:
            current_offset = 0
            for param in params: 
                fw.write(f"li $t1, { current_offset}")    
                fw.write(f'add $sp,$sp,$t1')       
                fw.write(f"move $a0, $sp")        
                fw.write(f'sub $sp,$sp,$t1')             
                fw.write(f'addi $sp,$sp,-{current_offset}')
                fw.write('sw $a0,0($sp)')              
                fw.write(f'addi $sp,$sp, {current_offset}')   
                current_offset += 4
            fw.write(f'addi $sp,$sp,-{current_offset}') 
            fw.write(f'jal {functionId}')  
            fw.write(f'addi $sp,$sp,{current_offset}')
       

    elif node[0] in [ '+', '-', '*', '/']:
        if(len (node[0]) > 1):
            compileCode(node[1][0], table, fw)
            fw.write('sw $a0 0($sp)')
            fw.write('addiu $sp $sp -4')
            compileCode(node[2][0], table, fw)
            fw.write('lw $t1 4($sp)')
            if node[0] is '+':
                fw.write('add $a0 $a0 $t1')
            elif node[0] is '-':
                fw.write('sub $a0 $a0 $t1')
            elif node [0] is '*': 
                fw.write("mult $t1, $a0") 
                fw.write("mflo $a0")     
            elif node[0] is '/':                   
                fw.write("div $t1, $a0")  
                fw.write("mflo $a0")      
            fw.write('addiu $sp $sp 4')
       

    elif node[0] is 'iteration_stmt':
        if node[1] == 'while':
            condition = node[2]
            fw.write(f"start-while{while_counter}:", tab=False) 

            compileCode(condition[1], table, fw)
            fw.write("sw $a0 0($sp)")
            fw.write(f'addi $sp,$sp,-4')
    
            compileCode(condition[2], table, fw) 
            fw.write(f"lw $t1 4($sp)")         
            fw.write(f"addi $sp,$sp,4") 


            if condition == '==':
                fw.write(f"beq $t1, $a0, while{while_counter}") 
            elif condition == '!=':
                fw.write(f"bne $t1, $a0, while{while_counter}") 
            elif condition  == '<':
                fw.write(f"blt $t1, $a0, while{while_counter}") 
            elif condition == '<=':
                fw.write(f"ble $t1, $a0, while{while_counter}") 
            elif condition == '>':
                fw.write(f"bgt $t1, $a0, while{while_counter}") 
            elif condition == '>=':
                fw.write(f"bge $t1, $a0, while{while_counter}") 
           
            fw.write(f"j end-while{while_counter}")           
            fw.write(f"while{while_counter}:", tab=False)    
            for statement in node[3]:
                compileCode(statement,table,fw)
            fw.write(f"j start-while{while_counter}")         
            fw.write(f"end-while{while_counter}:", tab=False) 
            while_counter += 1;
       

    elif node[0] is 'selection_stmt':
        if node[1] == 'if':
            condition = node[2][0]

            compileCode(node[2][1], table, fw)
            fw.write("sw $a0 0($sp)")
            fw.write(f'addi $sp,$sp,-4')


            compileCode(node[2][2], table, fw) 
            fw.write(f"lw $t1 4($sp)")          
            fw.write(f"addi $sp,$sp,4") 
            
            
            if condition == '==':
                fw.write(f"beq $t1, $a0, if{if_counter}") 
            elif condition == '!=':
                fw.write(f"bne $t1, $a0, if{if_counter}") 
            elif condition  == '<':
                fw.write(f"blt $t1, $a0, if{if_counter}") 
            elif condition == '<=':
                fw.write(f"ble $t1, $a0, if{if_counter}") 
            elif condition== '>':
                fw.write(f"bgt $t1, $a0, if{if_counter}") 
            elif condition == '>=':
                fw.write(f"bge $t1, $a0, if{if_counter}") 
            #fw.write(f"j else{if_counter}") 
            fw.write(f"if{if_counter}:", tab=False) 
            for statement in node[1]: 
                compileCode(statement,table,fw)
            #fw.write(f"j {contLabel}") 
            #fw.write(f"{falseLabel}:", tab=False) 
            #if there is an else
            if_counter += 1;
            if len(node) > 4:
                for statement in node[5]: 
                    compileCode(statement,table,fw)


            #fw.write(f"{contLabel}:", tab=False) 

       

    elif node[0] is 'return_stmt':
        fw.write(f'addi $sp,$sp') 
        fw.write(f'jr $ra') 
    
    else:
        for child in node[1:]:
            if type(child) is list:
                compileCode(child, table, fw)


    