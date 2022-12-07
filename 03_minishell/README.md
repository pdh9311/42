# Minishell
Minishell is a simple shell.
1. Create execute file command : `make`
2. Execute command : `./minishell`
3. A test command that verifies the original shell command : `make tester`  
	You can check it by pressing `ENTER`.

# contributors
<a href="https://github.com/pdh9311">
	<img src="https://github.com/pdh9311.png?size=50">
</a>
<a href="https://github.com/42joonpark">
	<img src="https://github.com/42joonpark.png?size=50">
</a>

# Make
> Note: `readline is required.`
```sh
brew install readline
```
```sh
apt install -y lib32readline-dev libreadline-dev
```
add includes path and dir in Makefile

# Builtins
1. [cd](#cd)
2. [pwd](#pwd)
3. [echo](#echo)
4. [exit](#exit)
5. [export](#export)
6. [env](#env)
7. [unset](#unset)

# cd [option] [dst]
### change the working directory ###
- '-' \
	cd to OLDPWD

- '~' \
	cd to $HOME dir

- relative path

- absolute path

# pwd
### return working directory name ###

# echo
### write arguments to the standard output ###

- n

	Do not print the trailing newline character.

# exit
### Close the terminal ###
- Argument : no \
	Terminal is terminated.
	```sh
	zsh$ bash
	bash$ exit
	exit
	zsh$
	```

- Argument : number < INT_MAX \
	Argument of integer value is returned to the parent process and terminated.
	```sh
	zsh$ bash
	bash$ exit 7
	exit
	zsh$ echo $?
	7
	```



# export
### set the export attribute for variables ###

Only the form of <span style="color:red"> a=b </span> is recognized.

Forms such as a=b, a=b, 'a'=b, a='b'etc are not allowed.

Duplicate names are changed to new values.

# env
### print environment ###

# unset
### Remove variable ###

# errors
any input with ; or \ are syntax error.

# Diagram #
![Untitled Diagram drawio](https://user-images.githubusercontent.com/83530766/142713997-1d859eb4-43f8-4737-833b-8de1b0e59c34.png)

---
## 배운내용 Notion에서 확인
https://donpark.notion.site/minishell-1c2b003889a142a7a9295ad5a22f0bbf