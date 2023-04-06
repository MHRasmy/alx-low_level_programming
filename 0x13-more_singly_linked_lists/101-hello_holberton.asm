section .data
  hello db 'Hello, Holberton', 10

section .text
  global main
  extern printf

  main:
    push hello
    call printf
    add esp, 4
    ret
