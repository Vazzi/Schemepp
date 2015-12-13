
(define (load_edges e edges file)
    (if (eq? e 0)
        edges
        (load_edges (- e 1) (add_edge (read file) (read file) (read file) edges) file)
    )
)

(define ( load_queries q file edges k)
    (if (eq? q 0)
        #f
        (let ()
            (if (eq? k 0)
                #f
                (let () (if (eq? k 1) #f (write "")) (write "Case #")(write k)(write ""))
            )
            (findpath (cons (cons (read file) 0) #f) #f edges (read file))
            (load_queries (- q 1) file edges 0)
        )
    )
)

(define ( process n e q file k)
    (if (and (and (eq? n 0) (eq? e 0)) (eq? q 0))
        #f
        (let () 
            (load_queries q file (load_edges e #f file) k)
            (process (read file) (read file) (read file) file (+ k 1))
        )
    )
)

(define ( add_edge from to noise edges)
    (cons (cons (cons to from) noise) (cons (cons (cons from to) noise) edges))
)

(define (insert queue node noise)
    (if (eq? queue #f)
        (cons (cons node noise) #f)
        (if (> (cdar queue) noise)
             (cons (cons node noise) queue)
             (cons (car queue) (insert (cdr queue) node noise))
        )
    )
)

(define (top queue)
    (if (eq? queue #f)
        #f
        (car queue)
    )
)

(define ( is_not_closed node closed_nodes)
    (if (eq? closed_nodes #f)
        #t
        (if (eq? node (car closed_nodes))
            #f
            (is_not_closed node (cdr closed_nodes))
        )
    )
)

(define (close_node node closed_nodes)
    (if (eq? closed_nodes #f)
        (cons node #f)
        (if (eq? (car closed_nodes) node)
            closed_nodes
            (if (> (car closed_nodes) node)
                (cons node closed_nodes)
                (cons (car closed_nodes) (close_node node (cdr closed_nodes)))
            )
        )
    )
)

(define (expand node queue closed_nodes edges)
    (if (eq? edges #f)
        queue
        (if (and (eq? (car node) (caaar edges)) (is_not_closed (cdaar edges) closed_nodes))
            (if (< (cdr node) (cdar edges))
                (expand node (insert queue (cdaar edges) (cdar edges)) closed_nodes (cdr edges))
                (expand node (insert queue (cdaar edges) (cdr node)) closed_nodes (cdr edges))
            )
            (expand node queue closed_nodes (cdr edges))
        )
    )
)

(define (findpath queue closed_nodes edges finish)
    (if (eq? queue #f)
        (write "no-path")
        (if (eq? (car (top queue)) finish)
            (let () (write (cdr (top queue)))(write ""))
            (if (is_not_closed (car (top queue)) closed_nodes)
                (findpath (expand (top queue) (cdr queue) closed_nodes edges) (close_node (car (top queue)) closed_nodes) edges finish)
                (findpath (cdr queue) closed_nodes edges finish)
            )
        )
    )
)

(let ((*file* (open-input-file "data")))

(process (read *file*) (read *file*) (read *file*) *file* 1)
)