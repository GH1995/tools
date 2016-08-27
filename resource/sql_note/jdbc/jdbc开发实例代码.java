public class ConnectionDB
{
    public static void main(String[] args) 
    {
        COnnection conn = null;
        Statement stmt;

        String classforname = "com.microsoft.sqlserver.jdbc.SQLserver";             // jdbc驱动程序
        String url = "jdbc:sqlserver://localhost:1433;DatabaseName = bookdb";       // 连接服务器和数据库名称
        String uid = "sa";
        String pwd = "sa";

        
    /*  简写  
        ClassforName(classforname);     // 加载驱动程序
        conn = DriverManger.getConnection(url, uid, pwd);   // 建立与数据库的连接
        stmt = conn.createStatement();      // 创建statement对象
        ResultSet rs = stmt.executeQuery("select * from booktype"); //取结果集
    */


        /*
        *   加载驱动程序
        */
        try
        {
            ClassforName(classforname);
        }
        catch(ClassNotFoundException ex)
        {
            System.out.println("ClassNotFoundException");
        }


        /*
        *   建立与数据库的连接
        */
        try
        {
            conn = DriverManger.getConnection(url, uid, pwd);
        }
        catch
        {
            System.out.println("SQLException");
        }



        /*
        *   创建statement对象
        *   取结果集
        */
        try
        {
            stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("select * from booktype");

            if(rs.next())
            {
                System.out.println(rs.getString("TypeName"));
            }
        }
        catch (SQLException ex) 
        {
            System.out.println("SQLException ");
        }
    }
}