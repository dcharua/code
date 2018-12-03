#lang racket
"Daniel Charua Examen final"
;promedio
(define (suma list)
  (if (null? list) 0
      (+ (car list) (suma (cdr list)))
      )
)

(define (promedio list)
  (if (null? list) 0
      (/ (suma list) (length list))
      )
)
 