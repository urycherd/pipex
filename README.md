# pipex

This program executes in a following way:
`./pipex file1 cmd1 cmd2 file2`
It takes 4 arguments:
- file1 and file2 are file names.
- cmd1 and cmd2 are shell commands with their parameters.

Its behave exactly the same as the shell command below:<br/>
`$> < file1 cmd1 | cmd2 > file2`
