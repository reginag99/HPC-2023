let g:markdown_fenced_languages = ['julia']

set expandtab
set shiftwidth=4

nmap <Leader><Leader>m :NotebookEvaluate<CR>

let g:notebook_cmd='julia'
let g:notebook_stop='exit()'
let g:notebook_send0=''
let g:notebook_send='println(\"VIMJULIANOTEBOOK\")'
let g:notebook_detect='VIMJULIANOTEBOOK'
