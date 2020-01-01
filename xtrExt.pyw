# xtrExt.pyw - Extract from folder files with explicited extensions.
# Usage:
# xtrExt.pyw <source folder> <destination> <extensions>

#Improvements: ? search by regex ? 

import os, sys, re, shutil
if len(sys.argv) < 4:
	sys.exit('Error : Wrong arguments\nUsage : xtrExt.pyw <source folder> <destination> <extensions>')

srcFolder = sys.argv[1]
if not os.path.exists(srcFolder):
	sys.exit('Error : Source folder \''+srcFolder+'\' not found.')

dstFolder = sys.argv[2]
if not os.path.exists(dstFolder) or not os.path.isdir(dstFolder):
	sys.exit('Error : Destination folder \''+dstFolder+'\' not found.')
extensions = sys.argv[3:]

extCount = dict.fromkeys(extensions, 0)

for root, dirs, files in os.walk(srcFolder):
	for filename in files:
		for extension in extensions:
			matchName = re.match(r'.*\.' + extension + r'$', filename)
			if matchName:
				filepath = root + '/'+matchName.group()
				print(' --> ' + filepath)
				shutil.copy(filepath, dstFolder)
				extCount[extension] += 1

print ('Extraction complete')
for ext in extCount:
	print('  ' + str(extCount[ext]).zfill(2) + ' ' + ext + ' files')