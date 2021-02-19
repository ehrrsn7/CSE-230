column_names = ["hello", "there", "column1", "column2"]

question_marks = "?"
how_many_question_marks = len(column_names)
for i in range(how_many_question_marks - 1):
    question_marks += ",?"

print(question_marks)