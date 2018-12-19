 import java.util.*;
 import java.sql.*;

 public class QueryStu{
     static Scanner reader = new Scanner(System.in);
     static private Connection conn;
     static int sno = 1;
     public static void main(String args[]) {
         if (connect()){
             System.out.println("��ѯѧ�ź�����������ƥ�䣩����-��ͷ��ѯid��*������м�¼��exit������˳�.");
             String query;
             while (!((query=getNextLine()).equals("exit"))){
                if (query.length() == 0)break;
                if (query.equals("*")){
                    ResultSet rs = executeQuery("select * from stu ORDER BY num");
                    showStudents(rs);
                }
                else{
                    String v = query;
                    if (v.charAt(0) != '-'){
                        ResultSet rs = executeQuery("select * from stu where num like '%" + v + "%' or name like '%" + v +"%' order by num");
                        showStudents(rs);
                    }
                    else if (v.charAt(0) != '\n' && v.charAt(0) != ' '){
                        v = v.substring(1, v.length());
                        ResultSet rs = executeQuery("select * from stu where id=" + v);
                        showStudents(rs);
                    }
                    else break;
                }
             }
         }
         else{
             System.out.println("Connect Error!");
         }
     }	
    private static String getNextLine(){
        System.out.print(sno+">");
        sno++;
        return reader.nextLine();
    }
    // ��������
	private static boolean connect() {
		String connectString = "jdbc:mysql://172.18.187.230:53306/teaching9"
				+ "?autoReconnect=true&useUnicode=true&characterEncoding=UTF-8&&useSSL=false";
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection(connectString, "user", "123");
			return true;
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		return false;
	}
    //ִ��SQL��ѯ���, ���ؽ����
	static private ResultSet executeQuery(String sqlSentence) {
        Statement stat;
        ResultSet rs = null;
           
        try {
            stat = conn.createStatement();       //��ȡִ��sql���Ķ���
            rs = stat.executeQuery(sqlSentence); //ִ��sql��ѯ���������ݼ�
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return rs;
   }
   	//��ʾ��ѯ���
	private static void showStudents(ResultSet rs){
	    try {
            int i = 0;
	        while(rs.next()){
	          System.out.println(rs.getString("id") + " " + rs.getString("num") + " " + rs.getString("name"));		   
              i++;
            }
            System.out.println("[" + String.valueOf(i) + "����¼]" );
            
	    }
	    catch (Exception e) {
		System.out.println(e.getMessage());
	    }
	}
 }
