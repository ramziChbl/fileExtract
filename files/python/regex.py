import re
emailRegex = re.compile('''
                    [a-z]
                    [a-zA-Z0-9_.-]+
                    @
                    [a-zA-Z.-]+
                    \.
                    [a-zA-Z0-9]{2,4}
                    ''')
#print("Enter text:")
#email = input()
#print(email)
email = "adasdl kad;lkasd;lkas ramzi.chbl@esi.dz adasdasd"
mailReg = emailRegex.search(email)
print(mailReg)
