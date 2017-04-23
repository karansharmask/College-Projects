//Main Class file For fireCrackers And auto genrated Two constructor One with ID and another one Without ID

public class Cracker
{
    public Cracker(int iD, string nAME, string tYPEOFF, double pRICE, string iMAGEOF, string rEVIEW)
    {
        ID = iD;
        NAME = nAME;
        TYPEOFF = tYPEOFF;
        PRICE = pRICE;
        IMAGEOF = iMAGEOF;
        REVIEW = rEVIEW;
    }

    public Cracker(string nAME, string tYPEOFF, double pRICE, string iMAGEOF, string rEVIEW)
    {
        NAME = nAME;
        TYPEOFF = tYPEOFF;
        PRICE = pRICE;
        IMAGEOF = iMAGEOF;
        REVIEW = rEVIEW;
    }

    public int ID { get; set; }
    public string NAME { get; set; }
    public string TYPEOFF { get; set; }
    public double PRICE { get; set; }
    public string IMAGEOF { get; set; }
    public string REVIEW { get; set; }
}
