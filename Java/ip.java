import java.net.InetAddress;

public class ip {
    public static void main(String[] args) {
         try{
             InetAddress ip = InetAddress.getByName("目标主机的IP地址或者是目标主机的名称即可");
             System.out.println("IP地址为："+ip.getHostAddress());
             System.out.println("主机名为："+ip.getHostName());
         }catch (Exception e){
             e.printStackTrace();
         }
    }
}
