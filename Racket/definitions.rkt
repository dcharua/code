#lang racket

"sum function"
(define (suma a b)
  (+ a b)
  )
"sum and subtract in list form"
(define (suma-resta a b)
  (list (suma a b) (- a b)))

;(require racket/enter)
;(enter! "test.rkt")
;(current-directory ;#<path:/home/euge/>

;CONS and Append

(cons 'a '(1 2 3)) ; expresion + list
(cons '(a) '(1 2 3)) ; list + list

(append '( 1 2 3) '(4 5 6))

;Lists
(list 'a '(1 2) 1)

;bool expressions #t #f and not or
; todo en prefijo

;Predicados
(number? 4) ; true
(number? 'a) ; false

; (= 3 3) true solo funciona con numeros
; use (equal? '(a b) '(a b))


;funcion
(define (opera f a b)
  (f a b)
  )
; funcion member. es miembro de una lista?
(member 'a '(1 2 3 a))
(member 10 '(1 2 3))
"test"
(member '(a b) '(1 2 3 (a b)))


; length and reverse
(length '(1 2 3 4))
(reverse '(1 2 3 4))

; map, evaluates something through all elements
(map abs '(-1 23 -232 23 -23))

; change the sign function
(define (cambia a)
  (- a)
  )
; foldl, operador, valor inicial, lista
(foldl + 0 '(1 2 3))

; read equivalent scanf
;(define a (read))

; print
;(print '(hola mundo))
;(print "hola mundo")

;Lisp lo imprime dos veces
;(define (imprime a)
 ; (print a)
  ;)

; CONDITIONALS: if, case(switch case), cond(if anidados)
(if (< 4 5)
    1
    2)

(define (aprobado a b c)
  (if (< (/ (+ a b c ) 3)70)
         "si"
         "no"))


                   