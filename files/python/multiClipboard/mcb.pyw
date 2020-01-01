# mcb.pyw - Saves and loads pieces of text to the clipboard.
# Usage: 
#	py.exe mcb.pyw save <keyword> - Saves clipboard to keyword.
#	py.exe mcb.pyw <keyword> - Loads keyword to clipboard.
#	py.exe mcb.pyw list - Loads all keywords to clipboard.
#	py.exe mcb.pyw delete <keyword> - Delete keyword from file.
#	py.exe mcb.pyw print <keyword> - Print keyword entry.


import sys, shelve, pyperclip

if len(sys.argv) < 2 or len(sys.argv) > 3:
	sys.exit("Wrong number of arguments")

keywords = shelve.open('keywords')


if sys.argv[1] == 'save':
	if (len(sys.argv) != 3): #Wrong args number
		sys.exit('''Error : no keyword to save
--> Usage : py.exe mcb.pyw save <keyword> - Save clipboard to keyword.''')
	
	keywords[sys.argv[2]] = pyperclip.paste()	

elif sys.argv[1] == 'list':
	ll = list(keywords.keys())
	for l in ll:
		print(l + '\t-->\t'+ keywords[l])

elif sys.argv[1] == 'delete':
	if (len(sys.argv) != 3): #Wrong args number
		sys.exit('''Error : no keyword to delete
--> Usage : py.exe mcb.pyw delete <keyword> - Delete keyword entry.''')	
	del keywords[sys.argv[2]]

elif sys.argv[1] == 'print':
	if (len(sys.argv) != 3): #Wrong args number
		sys.exit('''Error : no keyword entry to print
--> Usage : py.exe mcb.pyw print <keyword> - Print keyword entry.''')

	if sys.argv[2] not in keywords.keys():
		sys.exit('''Error : keyword not found
--> Usage : py.exe mcb.pyw print <keyword> - Print keyword content.''')

	print(keywords[sys.argv[2]])


else:
	#Copy key to clipboard
	if sys.argv[1] not in keywords.keys():
		sys.exit('''Error : keyword not found
--> Usage : py.exe mcb.pyw <keyword> - Copy keyword content to clipboard.''')

	pyperclip.copy(keywords[sys.argv[1]])

keywords.close()
