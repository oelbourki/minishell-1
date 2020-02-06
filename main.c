// #include "minishell.h"


// int main()
// {

// 	// print_arg(path);
// 	t_command *head;
// 	head = NULL;
// 	// push_back1(&head,"ls",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"/usr/bin/wc",COMMAND);
// 	// push_back1(&head,">",REDOUT);
// 	// push_back1(&head,"123456789",STRING);

// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"<",REDIN);
// 	// push_back1(&head,"main.c",STRING);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"grep",COMMAND);
// 	// push_back1(&head,"main",STRING);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"otamn",STRING);
// 	// push_back1(&head,">",REDOUT);
// 	// push_back1(&head,"101010",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"99999999",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"1111111",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"2222222",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"find",COMMAND);
// 	// push_back1(&head,".",STRING);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"xargs",COMMAND);
// 	// push_back1(&head,"basename",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"99999999",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"11111111",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"echo",COMMAND);
// 	// push_back1(&head,"222222",STRING);
// 	// print_head(head);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,"|",PIPE);
// 	// push_back1(&head,"wc",COMMAND);
// 	// push_back1(&head,"-e",STRING);
// 	// push_back1(&head,"cd",COMMAND);
// 	// push_back1(&head,"123456777777",STRING);
// 	// push_back1(&head,";",SEMICOL);
// 	// push_back1(&head,"pwd",COMMAND);
// 	// push_back1(&head,"export",COMMAND);
// 	// push_back1(&head,"a=5",STRING);
// 	///////////
// 	// push_back1(&head,"cat",COMMAND);
// 	// push_back1(&head,">",REDIN);
// 	// push_back1(&head,"9090",STRING);
// 	// push_back1(&head,"ls",COMMAND);
// 	// push_back1(&head,"-l",STRING);
// 	// push_back1(&head,"functions.c",STRING);
// 	push_back1(&head,">",REDOUT);
// 	push_back1(&head,"1",STRING);
// 	push_back1(&head,">",REDOUT);
// 	push_back1(&head,"2",STRING);
// 	push_back1(&head,"ls",STRING);
// 	the_main(head);
// 	ft_lstclear_command(&head);
// 	return 0;
// }