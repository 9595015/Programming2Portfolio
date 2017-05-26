import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.Object;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class RequestAPIExample {
    public static void main(String[] args) throws IOException {
       System.out.println("Type the ticker of stock to be analyzed");
      Scanner sc = new Scanner(System.in);
        String ticker = sc.nextLine();
       
      String url = "http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.quotes%20where%20symbol%20in%20(%22" + ticker + "%22)&env=store://datatables.org/alltableswithkeys"; // this creates the url with the specific stock wanting to be analyzed

        // Create a URL and open a connection
        URL YahooURL = new URL(url);
        HttpURLConnection con = (HttpURLConnection) YahooURL.openConnection();

        // Set the HTTP Request type method to GET
        con.setRequestMethod("GET");

        BufferedReader in = new BufferedReader(
                new InputStreamReader(con.getInputStream()));
        String inputLine;
        StringBuilder response = new StringBuilder();

        while ((inputLine = in.readLine()) != null) {
            response.append(inputLine);
        }

        // close connection
        in.close();

        // response is the contents of the XML
        System.out.println(response.toString());
        System.out.println();
    
    Pattern a = Pattern.compile("<Ask>(.*?)</");
Matcher a1 = a.matcher(response);
while(a1.find())
{
  float ask = Float.parseFloat(a1.group(1)); 
  System.out.println("Ask Price for Stock is: " + ask); //this is the ask price for stock

      Pattern c = Pattern.compile("<Change>(.*?)</");
Matcher c1 = c.matcher(response);
while(c1.find())
{
   float change = Float.parseFloat(c1.group(1)); 
  System.out.println("Change in price for Stock is: " + change + "%"); //this is % change for stock

    Pattern eps = Pattern.compile("<EPSEstimateCurrentYear>(.*?)</");
Matcher eps1 = eps.matcher(response);
while(eps1.find())
{
    float earnings = Float.parseFloat(eps1.group(1)); 
  System.out.println("Estimate Earnings per Share: " + earnings); //this is estimated earnings per share for this year for stock
  
    Pattern dl = Pattern.compile("<DaysLow>(.*?)</");
Matcher dl1 = dl.matcher(response);
while(dl1.find())
{
   float dayslow = Float.parseFloat(dl1.group(1)); 
  System.out.println("The lowest price of the day for this stock: " + dayslow); //this is lowest price of the day for stock
  
      Pattern dh = Pattern.compile("<DaysHigh>(.*?)</");
Matcher dh1 = dh.matcher(response);
while(dh1.find())
{
    float dayshigh = Float.parseFloat(dh1.group(1)); 
  System.out.println("The highest price of the day for this stock: " + dayshigh); //this is highest price of the day for stock
  
     Pattern r = Pattern.compile("<PERatio>(.*?)</");
Matcher r1 = r.matcher(response);
while(r1.find())
{
    float peratio = Float.parseFloat(r1.group(1)); 
  System.out.println("Price Earnings Ratio for Stock: " + peratio); //this is the price earnings ratio for stock

   
 Stock stock1 = new Stock(ask, change, earnings, dayslow, dayshigh, peratio);   
    
        } 
       } 
      }
     } 
    } 
   }
  }
 }
