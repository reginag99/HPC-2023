au BufRead,BufNewFile *.jl  set ft=julia
au BufRead,BufNewFile *.jlmd  set ft=juliamarkdown
au BufReadPost,BufNewFile *.jlmd call NotebookStart()
