#chapter02\string.py
print("1".center(20))  #1行20个字符，居中对齐
print(format("121", "^20"))  #1行20个字符，居中对齐
print(format("12321", "^20"))  #1行20个字符，居中对齐
print("1".rjust(20,"*"))  #1行20个字符，右对齐, 加*号
print(format("121", "*>20"))    #1行20个字符，右对齐，加*号
print(format("12321", "*>20"))  #1行20个字符，右对齐，加*号
