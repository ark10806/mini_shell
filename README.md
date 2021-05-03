# mini_shell

 - mini_shell waits until the user enter a command.  
 - The command is parsed into a command token. ("ls -al" -> "ls", "-al")  
 - If the command is built-in command then execute the command without calling fork().  
 - If the command is not a built-in command then It runs process by calling system call fork() and mini_shell waits until the process ends.
    (if it is running in the background[&] then mini_shell do not wait.)
 - Repeat the above procedures until the user enters [quit].

 ## Features
   - It reduced time to search for built-in commands to **O(logn)-time** by using "**STL::set**".
   - It takes time to **insert and delete logs** that contains the line number and user commands
      **about O(1)-time** by defining "**Circular list**".
 
 ## built-in commands
   - [quit]: terminates mini_shell
   - [history]: show 100 latest command lines entered by the user.
   - [help]: show manuals.

 ## Building
It contains c++11 syntax / grammars. You can build mini_shell by using commad like:
```
g++ -std=c++11 mini_shell.cpp
```

<img width="80%" src="http://210.111.178.136/pstree.gif"/>
