#createDB.py
import sqlite3
# 创建SQLite数据库：c:\Python\chapter17\sales.db
con = sqlite3.connect(r"c:\Python\chapter17\sales.db")
# 创建表：regions，包含2个列，id和name
con.execute("create table region(id primary key, name)")

for row in con.execute("select * from region"):
    print(row)
