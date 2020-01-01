import os

totalSize = 0
for filename in os.listdir('/'):
    fileSize = os.path.getsize('/' + filename)
    print(filename +' : ' + str(fileSize))
    totalSize += os.path.getsize('/' + filename)
print(totalSize)
