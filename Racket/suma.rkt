#lang racket
(define (suma a b)
  (+ a b)
  )

(define (suma-resta a b)
  (list (suma a b) (- a b))
  )