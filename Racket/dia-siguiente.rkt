#lang racket
; Daniel Charua - A01017419 - 29/08/18

(define (dia-siguiente d m a)
  (cond
    [(< d 28)
     (list (+ 1 d) m a)]
    [(and (= d 28) (= m 2) (= (remainder a 4) 0))
     (list 29 2 a)]
    [(and (= d 28) (= m 2))
     (list 1 3 a)]
    [(and (= d 30) (or (= m 4) (= m 6) (= m 9) (= m 11)))
     (list 1 (+ 1 m) a)]
    [(or(= d 28) (= d 29) (= d 30))
     (list (+ 1 d) m a)]
    [(and (= d 31) (= m 12))
     (list 1 1 (+ a 1))]
    [(= d 31)
     (list 1 (+ 1 m) a)]
  )
)
  