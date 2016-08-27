#DBquery.py
import sqlite3
# 打开SQLite数据库：c:\Python\chapter17\sales.db
con = sqlite3.connect(r"c:\Python\chapter17\sales.db")
# 查询数据库表
cur = con.execute("select id, name from region")
# 循环输出结果
for row in cur:
    print(row)
