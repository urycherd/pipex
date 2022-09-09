# pipex

This program executes in a following way:
`./pipex file1 cmd1 cmd2 file2`
It takes 4 arguments:
- file1 and file2 are file names.
- cmd1 and cmd2 are shell commands with their parameters.

Used functions:
- open, close, read, write,
malloc, free, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
- ft_printf and any equivalent
I coded

Its behave exactly the same as the shell command below:<br/>
`$> < file1 cmd1 | cmd2 > file2`
