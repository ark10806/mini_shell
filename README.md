# mini_shell

 +mini_shell waits until the user enter a command.  
 +The command is parsed into a command token. ("ls -al" -> "ls", "-al")  
 (+)If the command is built-in command then execute the command without calling fork().  
 -If the command is not a built-in command then It runs process by calling system call fork() and mini_shell waits until the process ends.
    (if it is running in the background[&] then mini_shell do not wait.)
 -Repeat the above procedures until the user enters [quit].
 
 **built-in commands**
  1. [quit]: terminates mini_shell
  2. [history]: print 10 command lines entered by the latest user.
  3. [help]: print manual


ToDo-list:
 + Optimize Parser(): ignoring multiple tabs or spaces.
 - ReadMe 만들기.
 + Execute fork()
 - [help] manual 출력.
 - history size 100으로 수정.
 - execl Params조절.
