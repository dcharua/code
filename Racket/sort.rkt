#lang racket
; Daniel Charua - A01017419 - 2/11/18

;=====BUBBLE SORT =======
;Funcion Principal que llama a otra funcion
(define (bubbleSort list)
  (bubble (length list) list)
  )


; Funcion para hacer el swap dependiendo si es mayor o no
(define (swap list)
  (if (null? (cdr list)) ; Caso base se regresa la lista ordenada
      list 
      (if (< (car list) (car(cdr list))) 
          (cons (car list) (swap(cdr list)))
          (cons (car (cdr list)) (swap(cons (car list) (cdr(cdr list)))))
      )
   )
 )


; Funcion con el tamaño de la lista donde se hacer recursion con el swap
(define (bubble i list)
  (if (= i 1) ; Caso base, se cambian los ultimos dos numeros
      (swap list)
      (bubble (- i 1) (swap list)) ; Se llama swap y se reduce el contador 
  )
)


;=====MERGE SORT =======
;Funcion principal divide la lista en dos y se llama hasta que la lista no se puede dividir mas
(define (mergeSort list)
  (if (= (length list) 1); Caso base hay un elemento en la lista
       list; si no divide en dos y se hace el sort llamandose a si misma con una sublista
      (sortLists (mergeSort (splitStart list (/ (length list) 2))) (mergeSort (splitEnd list (/ (length list) 2)))
             )
      )
  )

; Funcion que hacer el sort de las dos listas
(define (sortLists list1 list2)
  (if (null? list1); Caso base 1 una lista esta vacia
      list2
      (if (null? list2); Caso base 2 la seguna lista esta vacia
          list1
          (if (<= (car list1) (car list2)); Si el primer elemento de la primera lista es mayor
              (cons (car list1) (sortLists (cdr list1) list2)); se llama a si mismo con el cdr de esa lista
              (cons (car list2) (sortLists list1 (cdr list2))); se llama a si mismo con el cdr de la otra lista
              )
          )
      )
  )

; Funcion que regresa la primera mitad de la lista
(define (splitStart lista size)
  (if (null? lista)
      '() ;Caso base la lista esta vacia
  (if (< size 2) ; si hay menos de dos elementos se regresa primer elemento de la lista
      (list (car lista))
      (cons (car lista) (splitStart (cdr lista) (- size 1))); si se puede dividr se queda con el car y llama a si mismo con el cdr de la lista
      )
    )
  )

; Funcion que regresa la segunda mitad de la lista
(define (splitEnd list size)
  (if (= size 0)
      list; Caso base se regresa la lista llena 
  (if (< size 2); si hay menos de dos elementos se regresa el resto de la lista
      (cdr list)
      (splitEnd (cdr list) (- size 1)); si se puede dividir se queda con el cdr de la lista
      )
    )
  )
