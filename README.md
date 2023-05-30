# StiglSoft VM

### What is it?
StiglSoft Virtual machine is program allowing users to execute their<br>
programs simply

### How to start with it?
You will need gcc/clang to compile the vm itself<br>
and if you want, you can use stiglsoftasm to make it easier<br>
for that you need dotnet too tho

### StiglSoftAsm syntax
```
Moves value AF to service reg[1]
    cpy 0xAF 1
Jumps
    jmp 0xA0

```