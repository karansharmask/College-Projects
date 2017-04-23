using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;
using System.Collections;
using System.Configuration;



public static class Connection

{
    private static SqlConnection conn;
    private static SqlCommand command;

    static Connection() //Connection ffrom The web Config file Named CrackerConnection
    {
        string connectionString = ConfigurationManager.ConnectionStrings["CrackerConnection"].ToString();
        conn = new SqlConnection(connectionString);
        command = new SqlCommand("", conn);
    }

    public static ArrayList GetCrackerByType(string crackerType) //Getting array list From Cracker for Products Page
    {
        ArrayList list = new ArrayList();
        string query = string.Format("SELECT * FROM FireCracker WHERE  tYPEOFF LIKE '{0}'", crackerType);

        try
        {
            conn.Open();
            command.CommandText = query;
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                int iD = reader.GetInt32(0);
                string nAME = reader.GetString(1);
                string tYPEOFF = reader.GetString(2);
                double pRICE = reader.GetDouble(3);
                string iMAGEOF = reader.GetString(4);
                string rEVIEW = reader.GetString(5);

                Cracker cracker = new Cracker(iD, nAME, tYPEOFF, pRICE, iMAGEOF, rEVIEW);
                list.Add(cracker);
            }
        }
        finally
        {
            conn.Close();
        }

        return list;
    }

    public static User LoginUser(string username, string password) //Login page query And Connection String checked
    {
        //Check if user exists
        string query = string.Format("SELECT COUNT(*) FROM FireCracker.dbo.users WHERE username = '{0}'", username);
        command.CommandText = query;

        try
        {
            conn.Open();
            int amountOfUsers = (int)command.ExecuteScalar();

            if (amountOfUsers == 1)
            {
                //User exists, check if the passwords match
                query = string.Format("SELECT password FROM users WHERE username = '{0}'", username);
                command.CommandText = query;
                string dbPassword = command.ExecuteScalar().ToString();

                if (dbPassword == password)
                {
                    //Passwords match. Login and password data are known to us.
                    //Retrieve further user data from the database
                    query = string.Format("SELECT email  FROM users WHERE username = '{0}'", username);
                    command.CommandText = query;

                    SqlDataReader reader = command.ExecuteReader();
                    User user = null;

                    while (reader.Read())
                    {
                        string email = reader.GetString(0);
                       

                        user = new User(username, password, email);
                    }
                    return user;
                }
                else
                {
                    //Passwords do not match
                    return null;
                }
            }
            else
            {
                //User does not exist
                return null;
            }
        }
        finally
        {
            conn.Close();
        }
    }


    public static string RegisterUser(User user) //Registration of User starts 
    {
        //Check if user exists
        string query = string.Format("SELECT COUNT(*) FROM users WHERE username = '{0}'", user.UserName);
        command.CommandText = query;

        try
        {
            conn.Open();
            int amountOfUsers = (int)command.ExecuteScalar();

            if (amountOfUsers < 1)
            {
                //User does not exist, create a new user
                query = string.Format("INSERT INTO users VALUES ('{0}', '{1}', '{2}')", user.UserName, user.Password,
                                      user.Email);
                command.CommandText = query;
                command.ExecuteNonQuery();
                return "User registered!";
            }
            else
            {
                //User exists
                return "A user with this name already exists";
            }
        }
        finally
        {
            conn.Close();
        }
    }

}
