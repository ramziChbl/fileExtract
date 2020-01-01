# xtrExt.pyw - Extract from folder files with explicited extensions.
# Usage:
# xtrExt.pyw <source folder> <destination> <extensions>

import os, sys

if len(sys.argv) < 4:
	sys.exit('Error : Wrong arguments\nUsage : xtrExt.pyw <source folder> <destination> <extensions>')

for root, dirs, filenames in os.walk()	