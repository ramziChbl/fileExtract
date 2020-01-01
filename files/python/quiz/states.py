import random
states = {'Alabama': 'Montgomery', 'Alaska': 'Juneau', 'Arizona': 'Phoenix',
'Arkansas': 'Little Rock', 'California': 'Sacramento', 'Colorado': 'Denver',
'Connecticut': 'Hartford', 'Delaware': 'Dover', 'Florida': 'Tallahassee',
'Georgia': 'Atlanta', 'Hawaii': 'Honolulu', 'Idaho': 'Boise', 'Illinois':
'Springfield', 'Indiana': 'Indianapolis', 'Iowa': 'Des Moines', 'Kansas':
'Topeka', 'Kentucky': 'Frankfort', 'Louisiana': 'Baton Rouge', 'Maine':
'Augusta', 'Maryland': 'Annapolis', 'Massachusetts': 'Boston', 'Michigan':
'Lansing', 'Minnesota': 'Saint Paul', 'Mississippi': 'Jackson', 'Missouri':
'Jefferson City', 'Montana': 'Helena', 'Nebraska': 'Lincoln', 'Nevada':
'Carson City', 'New Hampshire': 'Concord', 'New Jersey': 'Trenton', 'New Mexico':
'Santa Fe', 'New York': 'Albany', 'North Carolina': 'Raleigh',
'North Dakota': 'Bismarck', 'Ohio': 'Columbus', 'Oklahoma': 'Oklahoma City',
'Oregon': 'Salem', 'Pennsylvania': 'Harrisburg', 'Rhode Island': 'Providence',
'South Carolina': 'Columbia', 'South Dakota': 'Pierre', 'Tennessee':
'Nashville', 'Texas': 'Austin', 'Utah': 'Salt Lake City', 'Vermont':
'Montpelier', 'Virginia': 'Richmond', 'Washington': 'Olympia', 'West Virginia':
'Charleston', 'Wisconsin': 'Madison', 'Wyoming': 'Cheyenne'}

capitalsList = list(states.values())

for quiz in range(35):
	quizfile = open('quizFiles/quiz'+str(quiz+1).zfill(2)+'.txt', 'w')
	
	quizfile.write('Quiz number %s :\n' %(quiz+1))
	statesShuff = list(states.keys())
	random.shuffle(statesShuff)

	for qNumber in range(1, 51):
		quizfile.write( str(qNumber) + " - What is the capital of "+ statesShuff[qNumber - 1] +" ?\n")
	   	correctAnswer = states[statesShuff[qNumber - 1]];
	   	answers = [correctAnswer]
	   	ansNum = 1
	   	while ansNum < 4:
	   		answr = random.choice(capitalsList)
	   		if answr != correctAnswer:
	   			answers.insert(ansNum, answr)
	   			ansNum += 1
		random.shuffle(answers)
		for answ in range(0, 4):
			quizfile.write('\t' + chr(ord('A') + answ) + '. ' + answers[answ]+'\n')
		quizfile.write('\n')
#
 #   for i in range(rNum):
  #      quizfile.write('    ' + str(i+1) + ' - ' + answers[i] + '\n')
quizfile.close()