    .global _asmMain
    .extern _stdout2
   
_asmMain:   
    push c1
    push $4
    push $mat01
    call _matrix_identityf
    add $12, %esp
    
    push c2
    push $4
    push $mat02
    call _matrix_identityf
    add $12, %esp
    
    pushl $4
    pushl $4
    pushl $4
    pushl $mat01
    pushl $mat02
    pushl $mat03
    call _matrix_multiplyf
    add $24, %esp

    push $4
    push $4
    push $mat03
    push _stdout2
    call _matrix_dumpf
    add $16, %esp

    ret
    
    .section .data
mat01: .space 64
mat02: .space 64
mat03: .space 64
c1: .float 7.0
c2: .float 11.0
