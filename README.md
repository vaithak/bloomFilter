# bloomFilter
A C++ library for using bloom filters written using reference from Michael Schmatz post.  

## Usage 
  * Initialising BloomFilter class object with size of bit-array and number of hashes.  
  ```
    BloomFilter bf(1024*1024, 5);
  ```  
  
  * Add a new string in bit-array.(You will have to type cast it into an unsigned 8 bit int pointer).   
  ```
    string check = "Hello World";
    bf.add((uint8_t*)check.c_str(), check.size());
  ```  
  
  * Lookup for a string in bit-array.(You will have to type cast it into an unsigned 8 bit int pointer).    
  ```
    check = "Google";
    bool status  = bf.find((uint8_t*)check.c_str(), check.size());
    cout<<"Is "<<check<<" Possibly Contained = "<<status<<endl;
  ```  

## Analysis of Bloom Filters

![DEFINITION](https://tinyurl.com/yczw2ozy)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image1.png)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image2.png)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image3.png)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image4.png)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image5.png)  
![image](https://github.com/vaithak/bloomFilter/blob/master/images_for_analysis/image6.png)  
