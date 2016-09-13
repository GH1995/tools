nb = float(input("请输入本金："))
nr = float(input("请输入年利率："))
ny = int(input("请输入年份："))
amount = nb * (1 + nr/100)**ny
print("本金利率和为：", amount)