# workbench

## About

This program is a response to the monotony, and disarray that come with
notetaking in markdown. Markdown is a wonderful tool but, I've found that
keeping track of notes along with their PDF or HTML output can be a nightmare. I
needed an tool to organize, and help automate the process of document creation.

## Usage

**workbench** creates a binary data file in the directory where it is run. The
data file tracks the files you create with the workbench program. Essentially,
`workbench` is an abstraction over your default `$EDITOR`, and `pandoc`.

* Initialize current directory to use workbench
	- `workbench`
* Create a new markdown document
	- `workbench -n TITLE`
* List tracked files
	- `workbench -l`
* Edit an existing file
	- `workbench -e`
* Delete an item from the list
	- `workbench -d`
* Publish markdown to HTML
	- `workbench -f html -p`
* Publish markdown to PDF
	- `workbench -f pdf -p`

> I suggest creating subdirectories for topics, and using those as part of the
> title when creating a new note.

`mkdir Math`

`workbench -n Math/addition`

## TODO

In the future, I would like `workbench` to track subjects along with their
files. At the very least, I would like subdirectories to be created
automatically with the subject title.

I also need to clean up the 'publishing' process, and do some more error
handling.

Finally, `workbench` uses the system() function to run `pandoc`, and `$EDITOR`.
I need to figure out how to get the `exec()` functions to work because there is
no need to return control back to `workbench` after those programs are finished
running.
