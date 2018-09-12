#lang racket
(define (mult a b)
  (if (= a 0)
      0
      (+ b (mult(- a 1) b))))

(define (fac a)
  (if (= a 0)
      1
      (* a (fac (- a 1)))))

(define (sumList l)
  ;(if (null? l)
  (if (= (length l ) 0)
      0
      (+ (car l) (sumList (cdr l)))))

(define (opera in opr lis)
  (if (null? lis)
      in
      (opera (opr (car lis) in) opr (cdr lis))))

(define (reversa lis)
  (if (= (length lis) 0)
      '()
      (append (reversa ( cdr lis)) (list (car lis))))) 
      
      