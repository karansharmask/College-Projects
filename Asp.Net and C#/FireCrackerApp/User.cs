//Login and Registration User class And Auto Genrated Two constructor one with Id and Another one without ID
    public class User
    {
    public User(int id, string userName, string password, string email)
    {
        Id = id;
        UserName = userName;
        Password = password;
        Email = email;
    }

    public User(string userName, string password, string email)
    {
        UserName = userName;
        Password = password;
        Email = email;
    }

    public int Id { get; set; }
        public string UserName { get; set; }
        public string Password { get; set; }
        public string Email { get; set; }
       

    }
