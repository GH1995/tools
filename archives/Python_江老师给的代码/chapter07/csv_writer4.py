#csv_writer4.py
import csv
def writecsv4(csvfilepath):
    csv.register_dialect('mydialect', delimiter=':', quoting=csv.QUOTE_NONE)
    headers = ['学号', '姓名', '性别', '班级', '语文', '数学', '英语']
    rows = [('101511', '宋颐园', '男', '一班', '72', '85', '82'),
            ('101513', '王二丫', '女', '一班', '75', '82', '51')]
    with open(csvfilepath,'w', newline='') as f:  
        f_csv = csv.writer(f, 'mydialect')   #指定格式化参数
        f_csv.writerow(headers)         #写入1行（标题）
        f_csv.writerows(rows)          #写入多行（数据）
if __name__ == '__main__':
    writecsv4(r'd:\scores4.csv')
