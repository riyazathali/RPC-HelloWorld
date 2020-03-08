# RPC-HelloWorld

Read README.md file first before starting. This is related to Remote procedure call - Hello World

1. First of all install the following,(These are Ubuntu commands)

```text
sudo apt install rpcbind
``` 

2. Start rpcbind service on your sever and if not running.
```text
/etc/init.d/rpcbind start
``` 

3. Check with the following command

```text
rpcinfo
``` 
This will show you the registration information in the terminal if it is successful.

4. Install GCC compiler to avoid the following error.
cannot find C preprocessor: cpp
rpcgen: C preprocessor failed with exit code 1

Use the following to install gcc
```text
sudo apt update
sudo apt install build-essential
sudo apt-get install manpages-dev
``` 
5. Check the GCC whether installed or not with the following.
```text
gcc --version
``` 

6. Check with the following command.
```text
rpcgen
``` 
7. If Command 'rpcgen' not found, but can be installed with the following command. 
```text
sudo apt install libc-dev-bin
``` 
Also, This is optional. But if there is not rpcbind service not installed or not started on your server you will get the following error message. At that time installing the above package is really good to get rid of that error.
Error : Cannot register service: RPC: Unable to receive; errno = Connection refused
or else try to start the rpcbind again if rpcbind is already installed as below.
```text
/etc/init.d/rpcbind start
``` 
8. Create a new directory and create a new within that directory as hw.x
```text
mkdir rpc
touch hw.x
``` 
9. Open the hw.x and paste the create the code as in the hw.x in the github repo. To create the client stub and server stub we have to write the the following file first. Following is a simpe file which is used in the server end.
```text
sudo vim hw.x
``` 
10. Use the following command to compile this above hw.x file. Note that you should execute this command in the directory where the hw.x file resides. ‘-C ‘ in the command is for C language and ‘-a’ is to generate all the files including samples.
```text
rpcgen -a -C hw.x
``` 
You will get the following files as list in the rpc directory where you execute the above command.
```text
ls
``` 
Makefile.hw  hw.h  hw.x  hw_client.c  hw_clnt.c  hw_server.c  hw_svc.c

11. Replace the hw_client.c with the code in the hw_client.c which is in the git repo.
```text
sudo vim hw_client.c
press
esc
type the following to remove the whole existing code in the hw_client.c file
ggdG 
press i
copy code in the hw_client.c which is in the git repo and the  paste the code here.
press esc
press colon
and type 
wq! 
```
to save.

12. Do the same for hw_server.c by replacing the existing code with the code in the hw_server.c which is in the git repo.

13. Type the following Since we have changed those two files now we have to compile all the files again. It will generate all the object files with executables.
```text
make -f Makefile.hw
```
You will see the following files when you are listing down by ls command.
```text
	Makefile.hw
	hw.h
	hw.x
	hw_client
	hw_client.c
	hw_client.o
	hw_clnt.c
	hw_clnt.o
	hw_server
	hw_server.c
	hw_server.o
	hw_svc.c
	hw_svc.o
  ```

14. Use the following commands by opening up two terminals with same rpc dirctory and run the server in a one and client in the other.
```text
sudo ./hw_server 
``` 

```text
sudo ./hw_client localhost
``` 
You will see the following in the client side.
```text
Getting ready to call hello world
Back from hello world
Returning the string as below
Hello world!! I am Ali
``` 

At the same time you will see the following in the server side.
```text
getting ready to return value to the client side
Returning to the client...
``` 

