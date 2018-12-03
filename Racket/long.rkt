#lang racket

(define (hello lst)
  (cond ((null? lst) 0)
        (else (+ 1 (hello (cdr lst))))))