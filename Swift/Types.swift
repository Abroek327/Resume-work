//a program showing how to capture and pass swift data types
import Foundation

//int functions
func getInt()->Int
{
print("Enter your favoirte Integer")
let iNum: Int=Int (readLine()!)!
return iNum

}
func showInt(iNum:Int)->Void
{
let showInt: String="Your favorite Integer is \(iNum)"
print(showInt)
}

//float functions
func getFloat()->Float 
{
print("Enter your favorite float")
let fNum: Float=Float (readLine()!)!
return fNum
}

func showFloat(fNum:Float)
{
let showFlo: String="Your favorite float is \(fNum)"
print(showFlo)
}

//String functions
func getString()->String
{
print("Enter your favoirte word or phrase")
let inWord: String 
inWord=(readLine())!
return inWord
}

func showString(inWord:String)
{
let showWord: String="Your favorite word or phrase is \(inWord)"
print(showWord)
}


//double functions
func getDouble()->Double
{
print("Enter your favorite double")
let dNum: Double=Double (readLine()!)! //bug fixed: ...Double=Double(readline()) is not the same as Double=Double (readline())
return dNum
}

func showDouble(dNum:Double)
{
let showDub: String="Your favorite double is \(dNum)"
print(showDub)
}


//Boolean functions
func getBool()->Int
{
    print("0 or 1?")
    let s: Int=Int (readLine()!)!
    return s
}

func showBool(s:Int)->Void
{
    
    var myBool:Bool=true
    let show: String="The boolean is \(myBool)"

    if (s==0)
    {
        myBool=false
        let show: String="The boolean is \(myBool)" //need to redefine show to update myBool
        print(show)
    }
    else if(s>1||s<0)
    {
        print("Incorrect input")
        let re:Int=getBool()
        showBool(s:re)
    }
    else
    {
        print(show)
    }
    
}

//Char functions
func getChar()->Character
{
print("Enter your favorite character")
let inChar: Character=Character (readLine()!)
return inChar
}
func showChar(inChar:Character)

{
let showChar: String="Your favroite character is \(inChar)"
print(showChar)
}


//Int array functions; other data type implementation is the same 
func getArr()->[Int]
{
   
    print("Enter your 10 favorite Integers")
    var arr: [Int]=[Int](repeating: 0,count: 10)
    for i: Int in 0..<10{
        arr[i] = Int(readLine()!)!
    }
    return arr
    /*
    let input: String
    input=(readLine())!


    let arr: [Int]=input.split(separator: " ").map{ Int($0)!}
   // print(arr)
    return arr
    */
}

func showArr(arr:[Int])
{
    let yourArr: String="Your 10 favorite numbers are \(arr)"
    print(yourArr)
}


//int calls 
let gotInt: Int=getInt()
showInt(iNum:gotInt)

//float calls 
let gotFloat: Float=getFloat()
showFloat(fNum:gotFloat)

//string calls
let gotString: String=getString()
showString(inWord:gotString)

//double calls 
let gotDouble: Double=getDouble()
showDouble(dNum:gotDouble)

//boolean calls
let gotBool:Int=getBool()
showBool(s:gotBool)

//Char calls
let gotChar: Character=getChar()
showChar(inChar:gotChar)


let gotArr: Array=getArr()
showArr(arr:gotArr)