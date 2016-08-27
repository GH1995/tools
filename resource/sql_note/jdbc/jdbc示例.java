/*
    java程序---->jabd api---->jdbc驱动器------>数据库
*/



/*
    通过 Class.forName() 安装驱动程序
*/
    Class.forName("com.microsoft.jdbc.sqlserver.SQLServerDriver");

/*
*   数据库操作（四个接口）
*   Driver、Connection、Statement、ResultSet、Driver
*/

// 1. 用Connection接口建立与数据库连接
    String url = "jdbc:sqlserver://localhost:1433; DatabaseName:数据库名称;"
    String user = "用户名";
    String password = "密码";
    Connection conn = DriverManager.getConnection(url, user, password);

// 2. 用Statement接口创建和执行SQL语句
    Statement stmt = conn.createStatement();        // 创建接口对象
    stmt.executeQuery(String sql);                  // 执行查询
    stmt.executeUpdate(String sql);                 // 执行更新


// 3. 用ResultSet接口处理结果
    ResultSet rs = stmt.executeQuery(String sql);   
    rs.next;                                        // 移到到下一行
    re.getString(int col);                          // 获取列号为col的值
    rs.getString(String colName);                   // 获取列名为colName的值
