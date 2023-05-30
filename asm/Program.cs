using System;
using System.IO;

class Program{
    static byte ConvertHex(string str){
        if(str.Split('x').Length == 2)
            return Convert.ToByte(Convert.ToInt32(str, 16));
        return Convert.ToByte(str);
    }
    public static void Main(string[] args){
        List<byte> bytes = new();
        string filename = "../program.sasm";
        string[] lines = File.ReadAllLines(filename);
        foreach(string line in lines){
            string[] parts = line.Split(' ');
            switch(parts[0]){
                case "mov":
                    bytes.Add(1);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "cpy":
                    bytes.Add(2);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "exit":
                    bytes.Add(3);
                    break;
                case "print":
                    bytes.Add(4);
                    break;
                case "read":
                    bytes.Add(5);
                    break;
                case "add":
                    bytes.Add(6);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "sub":
                    bytes.Add(7);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "jmp":
                    bytes.Add(8);
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                default:
                    bytes.Add(0);
                    break;
            }
            FileStream fs = File.OpenWrite("../program.bin");
            fs.Write(bytes.ToArray(),0,bytes.Count);
            fs.Close();
        }
    }
}