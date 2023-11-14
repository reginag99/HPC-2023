map <silent> j gj
map <silent> k gk

set scrolloff=15
filetype indent off

set number

let g:tex_flavor = 'latex'

let g:neomake_tex_enabled_makers = ['lacheck']

let g:tagbar_type_tex = {
      \ 'ctagstype' : 'latex',
      \ 'kinds'     : [
        \ 's:sections',
        \ 'g:graphics:0:0',
        \ 'l:labels'
      \ ],
      \ 'sort'      : 0,
    \ }
"        \ 'r:refs:1:0',
"        \ 'p:pagerefs:1:0'


let g:vimtex_compiler_latexmk = {
\   'background' : 0,
\   'build_dir' : '',
\   'callback' : 1,
\   'continuous' : 1,
\   'options' : [
\     '-pdf',
\     '-verbose',
\     '-file-line-error',
\     '-synctex=1',
\     '-interaction=nonstopmode',
\   ],
\}
nmap <Leader><Leader>m :VimtexCompile<CR>
"this can be removed with neovim 0.2.0; it's related to a bug in previous
"versions
let g:vimtex_quickfix_latexlog = {'fix_paths':0}

let g:deoplete#enable_at_startup = 1
let g:deoplete#enable_smart_case = 1

if !exists('g:deoplete#omni#input_patterns')
    let g:deoplete#omni#input_patterns = {}
endif
let g:deoplete#omni#input_patterns.tex = '\\(?:'
      \ .  '\w*cite\w*(?:\s*\[[^]]*\]){0,2}\s*{[^}]*'
      \ . '|\w*ref(?:\s*\{[^}]*|range\s*\{[^,}]*(?:}{)?)'
      \ . '|hyperref\s*\[[^]]*'
      \ . '|includegraphics\*?(?:\s*\[[^]]*\]){0,2}\s*\{[^}]*'
      \ . '|(?:include(?:only)?|input)\s*\{[^}]*'
      \ . '|\w*(gls|Gls|GLS)(pl)?\w*(\s*\[[^]]*\]){0,2}\s*\{[^}]*'
      \ . '|includepdf(\s*\[[^]]*\])?\s*\{[^}]*'
      \ . '|includestandalone(\s*\[[^]]*\])?\s*\{[^}]*'
      \ .')'
