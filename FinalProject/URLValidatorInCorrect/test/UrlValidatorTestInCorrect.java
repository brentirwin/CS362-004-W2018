import junit.framework.TestCase;

import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTestInCorrect extends TestCase {


   public UrlValidatorTestInCorrect(String testName) {
      super(testName);
   }

	public void testManualTest(){
		String[] schemes = {"http","https"};
		String[] urls = {"http://foo.bar.com/",
				"foo.bar.com/",
				"http://foo.bar.com",
				"http://foobarcom/",
				"http:/foo.bar.com",
				"https://foo.bar.com/baz",
				"ftp://foo.com/bar.baz"
		};
		boolean[] validity ={true,
				false,
				true,
				false,
				false,
				true,
				true,
		};

		UrlValidator urlVal1 = new UrlValidator(schemes);
		for (int i = 0; i < urls.length ; i++) {
			System.out.println(urls[i]);
			assertEquals(urlVal1.isValid(urls[i]),validity[i]);
		}
	}

   public void testManualTestExample()
   {
//You can use this function to implement your manual testing	   
	   String[] schemes = {"http","https"};
	   UrlValidator urlVal1 = new UrlValidator(schemes);
	   if (urlVal1.isValid("ftp://foo.bar.com/")) {
		   System.out.println("url is valid");
	   } else {
		   System.out.println("url is invalid");
	   }
	   
	   UrlValidator urlVal2 = new UrlValidator();
	   if (urlVal2.isValid("ftp://foo.bar.com/")) {
		   System.out.println("url is valid");
	   } else {
		   System.out.println("url is invalid");
	   }
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   // These should all be invalid
	   String[] urls = {
			   "3htt://go.com",
			   "http:/go.com",
			   "http:go.com",
			   "://go.com",
			   "256.256.256.256",
			   "1.2.3.4.5",
			   "1.2.3",
			   ".1.2.3.4",
			   "go.a",
			   "go.ala",
			   "go.laa",
			   "aaa.",
			   ".aaa",
			   "aaa",
			   "",
			   "go.com:-1",
			   "go.com:65636",
			   "go.com:65a",
			   "go.com/..",
			   "go.com/../",
			   "go.com/..//file",
			   "go.com/test1//file"
	   };
	   testIsValid(urls);
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   // These should all be valid
	   String[] urls = {
			"http://www.google.com:80/test1?action=view",
			"ftp://go.com:65536/t123",
			"h3t://go.au:0/$12?Action=edit&mode=up",
			"0.0.0.0:0/test1/",
			"255.255.255.255/test1/file",
			"https://255.com/test1/file"
	   };
	   testIsValid(urls);
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid(String[] urls)
   {
	   //You can use this function for programming based testing
	   UrlValidator urlVal = new UrlValidator();
	   for (int i = 0; i < urls.length; i++)
	   {
		   if (urlVal.isValid(urls[i])) {
			   System.out.println(urls[i] + " - url is valid");
		   } else {
			   System.out.println(urls[i] + " - url is invalid");
		   }
	   }
   }

   public int randint(int bound){

       Random rand = new Random();
       int index = rand.nextInt(bound);
       index -=1;
       if(index<0){
           index = index*-1;
       }
       return index;
   }

   //Generates and tests 1000 valid domains
    public void testProgrammingHostnames(){

        UrlValidator urlVal = new UrlValidator();

        //Selected domains chosen that will always be a valid TLD as well as domain name
        String[] domains = {
                "today",
                "tokyo",
                "travel",
                "school",
                "room",
                "red",
                "party",
                "page",
                "com",
                "netflix",
                "host",
                "fire",
                "download",
                "cool",
                "bike",
                "aaa",
        };

        //Valid generated subdomains test
        for (int i = 0; i < 1000 ; i++) {
            String subdomain = "http://";
            for (int j = 0; j < randint(6)+2; j++) {
                if(!(subdomain.charAt(subdomain.length()-1) == '/')){
                    subdomain+=".";
                }
                int index = randint(domains.length - 1);
                subdomain+=domains[index];
            }
            assertTrue(urlVal.isValid(subdomain));
        }
    }

    //Test 1000 generated valid IPv4 addresses
    public void testProgrammingIPv4(){

       UrlValidator urlValidator = new UrlValidator();
       String[] ipblocks = {
               "100",
               "122",
               "130",
               "22",
               "44",
               "1",
               "2",
               "245",
               "201",
               "244",
               "78",
               "90",
               "101",
               "255",
               "0"
       };
        for (int i = 0; i < 1000 ; i++) {
            String address = "http://";
            for (int j = 0; j < 4; j++) {
                if(!(address.charAt(address.length()-1) == '/')){
                    address+=".";
                }
                int index = randint(ipblocks.length - 1);
                address+=ipblocks[index];
            }
            assertTrue(urlValidator.isValid(address));
        }
    }
   
   public void testProgrammingTest()
   {
	   // Create tuples of strings and 
	   String[] valid = {
			   "http://go.com",
			   "ftp://go.com",
			   "h3t://go.com",
			   "go.com",
			   "www.google.com",
			   "go.au",
			   "0.0.0.0",
			   "255.255.255.255",
			   "255.com",
			   "go.com:80",
			   "go.com:65535",
			   "go.com:0",
			   "go.com/test1",
			   "go.com/t123",
			   "go.com/$12",
			   "go.com/test1",
			   "go.com/",
			   "go.com/test1/file",
			   "go.com/?action=view",
			   "go.com/?action=edit&mode=up"
	   };
	   String[] invalid = {
			   "3htt://go.com",
			   "http:/go.com",
			   "http:go.com",
			   "://go.com",
			   "256.256.256.256",
			   "1.2.3.4.5",
			   "1.2.3",
			   ".1.2.3.4",
			   "go.a",
			   "go.ala",
			   "go.laa",
			   "aaa.",
			   ".aaa",
			   "aaa",
			   "",
			   "go.com:-1",
			   "go.com:65636",
			   "go.com:65a",
			   "go.com/..",
			   "go.com/../",
			   "go.com/..//file",
			   "go.com/test1//file"
	   };

       UrlValidator urlVal = new UrlValidator();
       for (int i = 0; i < valid.length; i++)
       {
           assertTrue(urlVal.isValid(valid[i]));
       }
       for (int i = 0; i < invalid.length; i++)
       {
           assertFalse(urlVal.isValid(invalid[i]));
       }
   }

}
