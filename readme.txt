Group Details :
1. Bhavik Dhandhalya - 2018H1030118P
2. Deependra Singh - 2018H1030132P


- I have already compiled all the files using "rpcgen nameofmyfile.x" command.

Que. How I have created Multiple Clients ? and How they are differentiated ?
Ans. In client file, I have defined "CLIENT_ADDRESS", I have started with number 1. If you want to change that CLIENT_ADDRESS, then you can find "#define CLIENT_ADDRESS 1" and at "1", you can use any ADDRESS/ID you want but It should be different than other ADDRESSES/IDs which are already used.

---------------------
| Steps to Execute. |  (Extract tar file and then follow this commands)
---------------------

1. Go to "test" directory using "cd" command.

2. Compile "client.c" file using "gcc -o client client.c square_clnt.c square_xdr.c -lnsl" command.

3. Compile "server.c" file using "gcc -o server server.c square_svc.c square_xdr.c -lrpcsvc -lnsl" command.

4. Run server using "./server" command.

5. Run client using "./client 127.0.0.1" command.
	- If you want to RUN on different machine then enter that machine's IP address.

6. RUN as many client as you want.
-----------------------------------------------------------------------------------------

If you want to add new Client then, Follow this steps.

1. Copy "test" folder and rename it to "test2" (I have already added 5 folders so rename it to "test6")
2. In "test2" folder, open client.c file and update "#define CLIENT_ADDRESS 1" to "#define CLIENT_ADDRESS 2".
	- Remember, If "#define CLIENT_ADDRESS X" is exist then you must use "#define CLIENT_ADDRESS X+1".
	- I am attaching 5 Folders that means, I am using "CLIENT_ADDRESS" from 1 to 5.
	- So, If you want to add new Client, It's Address should be "6". 

3. Execute the above 5 steps of execution to RUN the new client.

- The CLIENT_ADDRESS can be between 0 to 1024.