#lang racket
(define (opera string a b)
  (if ([equal? string "suma"])
      (+ a b)
  (if ([equal? string "resta"])
      (- a b)
   )
  )
)

(define (dias mes)
  (cond [(or (= mes 1) (= mes 3) (= mes 5) (= mes 7) (= mes 8) (= mes 10) (= mes 12)) 31]
        [(= mes 2) 28]
        [(or (= mes 4) (= mes 6) (= mes 9) (= mes 11)) 30]
))
