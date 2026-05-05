// ================================================================
//  CineStream — Movie Streaming Platform
//  Course Project | Object Oriented Programming in C++
//
//  OOP Concepts Covered:
//  Week 2  : Encapsulation       — private data + getters/setters
//  Week 3  : Constructors        — parameterized + destructor
//  Week 4  : Static              — static data + static functions
//  Week 5  : Inheritance         — single + multilevel
//  Week 6  : Polymorphism        — runtime via virtual functions
//  Week 6  : Operator Overload   — +, >, <, ==, <<
//  Week 6b : Function Overload   — same name, diff parameters
//  Week 7  : Abstract Classes    — pure virtual functions
//  Week 9  : Friend Class        — Analytics reads Platform private
//  Week 10 : Multiple Inherit.   — AdminUser : User, StreamingEngine
//  Week 11 : Templates           — WatchHistory<T>, Subscription<T>
//  Week 11 : Copy Constructor    — DynamicArray deep copy
//  Week 12 : Exception Handling  — custom exceptions, try/catch
//  Week 12 : STL Containers      — map, queue, stack
//  Week 13 : File Handling       — ofstream, ifstream, ios::app
//  Week 14 : Stack + Queue       — built on DynamicArray
// ================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class MediaContent {
private:
    int    contentID;
    string title;
    string language;
    double imdbRating;
    int    releaseYear;

public:
    MediaContent(int id, const string& t, const string& l,
                 double r, int y)
        : contentID(id), title(t), language(l),
          imdbRating(r), releaseYear(y) {}

    virtual ~MediaContent() {}  
    int    getContentID()   const { return contentID;   }
    string getTitle()       const { return title;        }
    string getLanguage()    const { return language;     }
    double getImdbRating()  const { return imdbRating;   }
    int    getReleaseYear() const { return releaseYear;  }

    void setTitle(const string& t)  { title = t;       }
    void setImdbRating(double r)    { imdbRating = r;  }

    virtual void   display()        const = 0;
    virtual string getContentType() const = 0;
    virtual double getDuration()    const = 0;

    virtual void play() const {
        cout << "[PLAY] " << title
             << " [" << getContentType() << "]\n";
    }
};

class StreamingEngine {
private:
    string serverRegion;
    int    bufferSizeMB;

public:
    StreamingEngine(const string& region, int buf)
        : serverRegion(region), bufferSizeMB(buf) {}

    virtual ~StreamingEngine() {}

    string getServerRegion() const { return serverRegion; }
    int    getBufferSize()   const { return bufferSizeMB; }

    virtual void   stream()             const = 0;
    virtual string getQuality()         const = 0;
    virtual int    getBitrate()         const = 0;
    virtual void   adjustBandwidth(int)       = 0;

    virtual void showStreamInfo() const {
        cout << "  Server:"  << serverRegion
             << " | Buffer:" << bufferSizeMB << "MB"
             << " | Quality:" << getQuality()
             << " | " << getBitrate() << "kbps\n";
    }
};

class User {
private:
    int    userID;
    string name;
    string email;
    string password; 

public:
    User(int id, const string& n, const string& e, const string& p)
        : userID(id), name(n), email(e), password(p) {}

    virtual ~User() {}

    int    getUserID() const { return userID; }
    string getName()   const { return name;   }
    string getEmail()  const { return email;  }

    bool checkPassword(const string& p) const { return password == p; }

    void setName(const string& n)  { name = n;  }
    void setEmail(const string& e) { email = e; }

    virtual string getAccountType() const = 0;
    virtual bool   canDownload()    const = 0;
    virtual bool   canWatchHD()     const = 0;
    virtual int    getScreenLimit() const = 0;
    virtual void   displayProfile() const = 0;

    virtual void showWelcome() const {
        cout << "Welcome, " << name
             << "! [" << getAccountType() << "]\n";
    }
};

class Episode : public MediaContent {
private:
    int    seasonNo;
    int    episodeNo;
    double durationMins;
    string synopsis;

public:
    Episode(int id, const string& t, const string& l,
            double r, int y, int s, int e, double d,
            const string& syn)
        : MediaContent(id, t, l, r, y),
          seasonNo(s), episodeNo(e),
          durationMins(d), synopsis(syn) {}

    int    getSeasonNo()  const { return seasonNo;  }
    int    getEpisodeNo() const { return episodeNo; }
    string getSynopsis()  const { return synopsis;  }

    string getContentType() const override { return "Episode"; }
    double getDuration()    const override { return durationMins; }

    void display() const override {
        cout << "    [S" << seasonNo << "E" << episodeNo << "] "
             << getTitle() << " (" << durationMins << "m)"
             << " — " << synopsis << "\n";
    }
    void play() const override {
        cout << "[EPISODE] S" << seasonNo << "E" << episodeNo
             << ": \"" << getTitle() << "\"\n";
    }
};

class Movie : public MediaContent {
private:
    string         genre;
    double         durationMins;
    string         director;
    string         ageRating;
    vector<string> cast;

public:
    Movie(int id, const string& t, const string& l,
          double r, int y, const string& g, double d,
          const string& dir, const string& age)
        : MediaContent(id, t, l, r, y),
          genre(g), durationMins(d),
          director(dir), ageRating(age) {}

    string getGenre()    const { return genre;    }
    string getDirector() const { return director; }
    string getAgeRating()const { return ageRating;}
    void   addCast(const string& a) { cast.push_back(a); }

    string getContentType() const override { return "Movie"; }
    double getDuration()    const override { return durationMins; }

    void display() const override {
        cout << "\n  ===== MOVIE =====\n";
        cout << "  ID       : " << getContentID()  << "\n";
        cout << "  Title    : " << getTitle()       << "\n";
        cout << "  Genre    : " << genre            << "\n";
        cout << "  Director : " << director         << "\n";
        cout << "  Duration : " << durationMins     << " mins\n";
        cout << "  Language : " << getLanguage()    << "\n";
        cout << "  IMDB     : " << getImdbRating()  << "/10\n";
        cout << "  Year     : " << getReleaseYear() << "\n";
        cout << "  Rating   : " << ageRating        << "\n";
        if (!cast.empty()) {
            cout << "  Cast     : ";
            for (const auto& a : cast) cout << a << "  ";
            cout << "\n";
        }
        cout << "  =================\n";
    }

    void play() const override {
        cout << "[MOVIE] Now playing: \""
             << getTitle() << "\" (" << durationMins << " mins)\n";
    }
};

class Series : public MediaContent {
private:
    string          genre;
    int             totalSeasons;
    string          status;       
    vector<Episode> episodes;     

public:
    Series(int id, const string& t, const string& l,
           double r, int y, const string& g,
           int seasons, const string& s)
        : MediaContent(id, t, l, r, y),
          genre(g), totalSeasons(seasons), status(s) {}

    void addEpisode(const Episode& ep) { episodes.push_back(ep); }

    string getGenre()        const { return genre;                 }
    int    getTotalSeasons() const { return totalSeasons;          }
    string getStatus()       const { return status;                }
    int    episodeCount()    const { return (int)episodes.size(); }

    string getContentType() const override { return "Series"; }

    double getDuration() const override {
        double total = 0;
        for (const auto& ep : episodes) total += ep.getDuration();
        return total;
    }

    void display() const override {
        cout << "\n  ===== SERIES =====\n";
        cout << "  ID       : " << getContentID()  << "\n";
        cout << "  Title    : " << getTitle()       << "\n";
        cout << "  Genre    : " << genre            << "\n";
        cout << "  Seasons  : " << totalSeasons     << "\n";
        cout << "  Episodes : " << episodes.size()  << "\n";
        cout << "  Status   : " << status           << "\n";
        cout << "  IMDB     : " << getImdbRating()  << "/10\n";
        cout << "  Year     : " << getReleaseYear() << "\n";
        cout << "  ------ Episode List ------\n";
        for (const auto& ep : episodes) ep.display();
        cout << "  ==================\n";
    }

    void play() const override {
        if (!episodes.empty()) {
            cout << "[SERIES] Auto-playing first episode of \""
                 << getTitle() << "\"\n";
            episodes[0].play();
        } else {
            cout << "[SERIES] No episodes for \""
                 << getTitle() << "\"\n";
        }
    }
};

class Documentary : public MediaContent {
private:
    string topic;
    string narrator;
    string productionHouse;
    double durationMins;
    bool   hasSubtitles;

public:
    Documentary(int id, const string& t, const string& l,
                double r, int y, const string& top,
                const string& nar, const string& prod,
                double d, bool subs)
        : MediaContent(id, t, l, r, y),
          topic(top), narrator(nar), productionHouse(prod),
          durationMins(d), hasSubtitles(subs) {}

    string getTopic()           const { return topic;           }
    string getNarrator()        const { return narrator;        }
    string getProductionHouse() const { return productionHouse; }
    bool   getHasSubtitles()    const { return hasSubtitles;    }

    string getContentType() const override { return "Documentary"; }
    double getDuration()    const override { return durationMins;  }

    void display() const override {
        cout << "\n  ===== DOCUMENTARY =====\n";
        cout << "  ID         : " << getContentID()    << "\n";
        cout << "  Title      : " << getTitle()         << "\n";
        cout << "  Topic      : " << topic              << "\n";
        cout << "  Narrator   : " << narrator           << "\n";
        cout << "  Production : " << productionHouse    << "\n";
        cout << "  Duration   : " << durationMins       << " mins\n";
        cout << "  Language   : " << getLanguage()      << "\n";
        cout << "  IMDB       : " << getImdbRating()    << "/10\n";
        cout << "  Year       : " << getReleaseYear()   << "\n";
        cout << "  Subtitles  : " << (hasSubtitles ? "Yes" : "No") << "\n";
        cout << "  =======================\n";
    }

    void play() const override {
        cout << "[DOC] Streaming: \""
             << getTitle() << "\" narrated by " << narrator << "\n";
    }
};

class FreeUser : public User {
private:
    int  minutesWatched;
    int  monthlyLimit;
    int  adsWatchedToday;
    bool adSupported;

public:
    FreeUser(int id, const string& n,
             const string& e, const string& p)
        : User(id, n, e, p),
          minutesWatched(0), monthlyLimit(1800),
          adsWatchedToday(0), adSupported(true) {}

    int getRemainingMins() const { return monthlyLimit - minutesWatched; }

    void watchContent(int mins) {
        if (minutesWatched + mins > monthlyLimit) {
            cout << "[FREE] Monthly limit reached! Upgrade to Premium.\n";
            return;
        }
        minutesWatched += mins;
        adsWatchedToday++;
        cout << "[AD] Watching a 30-second ad...\n";
        cout << "[FREE] Enjoy! (" << getRemainingMins()
             << " mins remaining this month)\n";
    }

    string getAccountType() const override { return "Free";  }
    bool   canDownload()    const override { return false;   }
    bool   canWatchHD()     const override { return false;   }
    int    getScreenLimit() const override { return 1;       }

    void displayProfile() const override {
        cout << "\n  ===== USER PROFILE =====\n";
        cout << "  ID        : " << getUserID()      << "\n";
        cout << "  Name      : " << getName()         << "\n";
        cout << "  Email     : " << getEmail()        << "\n";
        cout << "  Account   : " << getAccountType()  << "\n";
        cout << "  Screens   : " << getScreenLimit()  << "\n";
        cout << "  Downloads : No\n";
        cout << "  HD Access : No\n";
        cout << "  Ads       : Yes\n";
        cout << "  Watched   : " << minutesWatched
             << " / " << monthlyLimit << " mins\n";
        cout << "  ========================\n";
    }

    void showWelcome() const override {
        cout << "Welcome, " << getName()
             << "! FREE plan - " << getRemainingMins()
             << " mins remaining.\n";
        cout << "Upgrade to Premium for unlimited, ad-free streaming!\n";
    }
};

class PremiumUser : public User {
private:
    string         plan;
    double         monthlyPrice;
    int            screenLimit;
    bool           ultraHDEnabled;
    vector<string> downloadedTitles;
    string         renewalDate;

public:
    PremiumUser(int id, const string& n, const string& e,
                const string& p, const string& pl)
        : User(id, n, e, p), plan(pl), renewalDate("2025-12-01") {
        if (pl == "Basic")         { monthlyPrice=9.99;  screenLimit=2; ultraHDEnabled=false; }
        else if (pl == "Standard") { monthlyPrice=14.99; screenLimit=4; ultraHDEnabled=false; }
        else                       { monthlyPrice=19.99; screenLimit=6; ultraHDEnabled=true;  }
    }

    string getPlan()         const { return plan;          }
    double getMonthlyPrice() const { return monthlyPrice;  }
    bool   isUltraHD()       const { return ultraHDEnabled;}

    void downloadTitle(const string& t) {
        downloadedTitles.push_back(t);
        cout << "[PREMIUM] \"" << t << "\" downloaded for offline.\n";
    }
    void showDownloads() const {
        cout << "  Downloaded titles (" << downloadedTitles.size() << "):\n";
        for (int i=0; i<(int)downloadedTitles.size(); i++)
            cout << "  " << i+1 << ". " << downloadedTitles[i] << "\n";
    }

    string getAccountType() const override { return "Premium(" + plan + ")"; }
    bool   canDownload()    const override { return true;           }
    bool   canWatchHD()     const override { return true;           }
    int    getScreenLimit() const override { return screenLimit;    }

    void displayProfile() const override {
        cout << "\n  ===== USER PROFILE =====\n";
        cout << "  ID        : " << getUserID()       << "\n";
        cout << "  Name      : " << getName()          << "\n";
        cout << "  Email     : " << getEmail()         << "\n";
        cout << "  Account   : " << getAccountType()   << "\n";
        cout << "  Plan      : " << plan               << "\n";
        cout << "  Price     : $" << monthlyPrice << "/month\n";
        cout << "  Screens   : " << screenLimit        << "\n";
        cout << "  Downloads : Yes\n";
        cout << "  HD Access : Yes\n";
        cout << "  Ultra HD  : " << (ultraHDEnabled ? "Yes" : "No") << "\n";
        cout << "  Renewal   : " << renewalDate        << "\n";
        cout << "  Downloads : " << downloadedTitles.size() << " titles\n";
        cout << "  ========================\n";
    }

    void showWelcome() const override {
        cout << "Welcome back, " << getName()
             << "! Enjoy unlimited " << plan << " streaming.\n";
        if (ultraHDEnabled) cout << "4K Ultra HD is enabled.\n";
    }
};

class Rating {
private:
    int    contentID;
    int    userID;
    double score;
    string reviewText;
    string datePosted;

public:
    Rating(int cid, int uid, double s,
           const string& r, const string& d)
        : contentID(cid), userID(uid),
          reviewText(r), datePosted(d) {
        setScore(s);
    }

    int    getContentID()  const { return contentID;  }
    int    getUserID()     const { return userID;     }
    double getScore()      const { return score;      }
    string getReview()     const { return reviewText; }
    string getDatePosted() const { return datePosted; }

    // WEEK 2 — ENCAPSULATION: validated setter
    void setScore(double s) {
        score = (s < 1.0) ? 1.0 : (s > 5.0) ? 5.0 : s;
    }

    // WEEK 6 — OPERATOR OVERLOADING
    bool   operator>(const Rating& o)  const { return score > o.score;  }
    bool   operator<(const Rating& o)  const { return score < o.score;  }
    bool   operator==(const Rating& o) const { return score == o.score; }
    Rating operator+(const Rating& o)  const {
        return Rating(contentID, 0, (score+o.score)/2.0,
                      "Averaged rating", datePosted);
    }

    friend ostream& operator<<(ostream& os, const Rating& r) {
        os << "Rating[Content#" << r.contentID
           << " User#" << r.userID
           << " Score:" << r.score << "/5"
           << " \"" << r.reviewText << "\"]";
        return os;
    }

    void display() const {
        cout << "  Score: " << score << "/5"
             << " | User#" << userID
             << " | " << datePosted << "\n"
             << "  \"" << reviewText << "\"\n";
    }

    void displayStars() const {
        cout << "  [";
        for (int i=0; i<(int)score; i++)    cout << "*";
        for (int i=(int)score; i<5; i++) cout << "-";
        cout << "] " << score << "/5\n";
    }
};

template<typename T>
class WatchHistory {
private:
    vector<T> history;
    int       maxSize;
    string    ownerName;

public:
    WatchHistory(const string& owner, int max = 50)
        : ownerName(owner), maxSize(max) {}

    void add(const T& content) {
        if ((int)history.size() >= maxSize)
            history.erase(history.begin());
        history.push_back(content);
        cout << "[HISTORY] Added \"" << content.getTitle()
             << "\" for " << ownerName << "\n";
    }

    bool hasWatched(int id) const {
        for (const auto& item : history)
            if (item.getContentID() == id) return true;
        return false;
    }

    double totalWatchTime() const {
        double t = 0;
        for (const auto& item : history) t += item.getDuration();
        return t;
    }

    void display() const {
        cout << "\n  === Watch History: " << ownerName << " ===\n";
        if (history.empty()) { cout << "  Empty.\n"; return; }
        for (int i=0; i<(int)history.size(); i++)
            cout << "  " << i+1 << ". ["
                 << history[i].getContentType() << "] "
                 << history[i].getTitle()
                 << " (" << history[i].getDuration() << "m)\n";
        cout << "  Total watch time: " << totalWatchTime() << " mins\n";
    }
};

struct MonthlyPlan {
    string name = "Monthly"; double price = 14.99; int days = 30;
    string info() const { return "Monthly ($14.99/month)"; }
};
struct AnnualPlan {
    string name = "Annual"; double price = 119.99; int days = 365;
    string info() const { return "Annual ($119.99/year — 2 months free)"; }
};
struct FamilyPlan {
    string name = "Family"; double price = 22.99;
    int days = 30; int members = 6;
    string info() const { return "Family ($22.99/month, 6 members)"; }
};

template<typename T = MonthlyPlan>
class Subscription {
private:
    T      plan;
    bool   active;
    int    daysLeft;
    string userEmail;
    int    renewals;

public:
    Subscription(const string& email, const T& p, int d)
        : userEmail(email), plan(p), active(true),
          daysLeft(d), renewals(0) {}

    bool   isActive()    const { return active;    }
    int    getDaysLeft() const { return daysLeft;  }
    string getEmail()    const { return userEmail; }
    T      getPlan()     const { return plan;      }

    void renew() {
        daysLeft += plan.days; renewals++;
        if (!active) active = true;
        cout << "[SUB] Renewed! " << daysLeft << " days left.\n";
    }
    void cancel() {
        active = false;
        cout << "[SUB] Cancelled. Access until expiry.\n";
    }

    void display() const {
        cout << "  === Subscription ===\n";
        cout << "  User   : " << userEmail        << "\n";
        cout << "  Plan   : " << plan.info()      << "\n";
        cout << "  Status : " << (active ? "Active" : "Inactive") << "\n";
        cout << "  Days   : " << daysLeft          << " remaining\n";
        cout << "  Renews : " << renewals          << " times\n";
        cout << "  ====================\n";
    }
};

class SDStream : public StreamingEngine {
    int bitrate; bool buffering;
public:
    SDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 2), bitrate(1500), buffering(false) {}
    string getQuality() const override { return "SD (480p)";  }
    int    getBitrate() const override { return bitrate;       }
    void stream() const override {
        cout << "[SD STREAM] 480p | " << bitrate
             << "kbps | Ads:Enabled | Server:" << getServerRegion() << "\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 500)  { bitrate=400;  buffering=true;  cout<<"[SD] Low — 400kbps, buffering.\n"; }
        else if (k < 1000) { bitrate=800;  buffering=false; cout<<"[SD] Moderate — 800kbps.\n"; }
        else               { bitrate=1500; buffering=false; cout<<"[SD] Good — 1500kbps.\n"; }
    }
};

class HDStream : public StreamingEngine {
    int bitrate, res;
public:
    HDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 8), bitrate(5000), res(1080) {}
    string getQuality() const override {
        return (res==1080) ? "HD (1080p)" : "HD (720p)";
    }
    int getBitrate() const override { return bitrate; }
    void stream() const override {
        cout << "[HD STREAM] " << res << "p | " << bitrate
             << "kbps | Ads:None | Server:" << getServerRegion() << "\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 1500) { bitrate=1200; res=720;  cout<<"[HD] Low — 720p.\n"; }
        else if (k < 6000) { bitrate=5000; res=1080; cout<<"[HD] Good — 1080p.\n"; }
        else               { bitrate=8000; res=1080; cout<<"[HD] Excellent — Max HD.\n"; }
    }
};

class UltraHDStream : public StreamingEngine {
    int bitrate; bool hdr, atmos;
public:
    UltraHDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 25), bitrate(15000),
          hdr(true), atmos(true) {}
    string getQuality() const override {
        return string("4K (2160p)") + (hdr?"+HDR":"") + (atmos?"+Atmos":"");
    }
    int getBitrate() const override { return bitrate; }
    void stream() const override {
        cout << "[4K STREAM] 2160p | " << bitrate
             << "kbps | HDR:" << (hdr?"On":"Off")
             << " | Atmos:" << (atmos?"On":"Off")
             << " | Ads:None\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 5000)  { bitrate=4000;  hdr=false; cout<<"[4K] Insufficient — dropping HDR.\n"; }
        else if (k < 20000) { bitrate=15000; hdr=true;  cout<<"[4K] Good — Dolby Vision.\n"; }
        else                { bitrate=25000; hdr=true; atmos=true; cout<<"[4K] Excellent — Max 4K.\n"; }
    }
};

class DynamicArray {
private:
    int* data;
    int  size_;
    int  capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i=0; i<size_; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int cap = 4) : size_(0), capacity(cap) {
        data = new int[capacity];
    }

    DynamicArray(const DynamicArray& other)
        : size_(other.size_), capacity(other.capacity) {
        data = new int[capacity];
        for (int i=0; i<size_; i++) data[i] = other.data[i];
        cout << "[DYNARRAY] Copy constructor — deep copy made.\n";
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this; 
        delete[] data;
        size_ = other.size_; capacity = other.capacity;
        data = new int[capacity];
        for (int i=0; i<size_; i++) data[i] = other.data[i];
        cout << "[DYNARRAY] Assignment — deep copy made.\n";
        return *this;
    }

    ~DynamicArray() { delete[] data; }

    void push(int v) { if (size_==capacity) resize(); data[size_++]=v; }
    void pop()       { if (size_>0) size_--;  }
    int  get(int i)  const { return data[i]; }
    int& operator[](int i) { return data[i]; }
    int  getSize()   const { return size_;   }
    bool isEmpty()   const { return size_==0;}

    void display() const {
        cout << "[ARR] [";
        for (int i=0; i<size_; i++) {
            cout << data[i];
            if (i < size_-1) cout << ",";
        }
        cout << "] size=" << size_ << " cap=" << capacity << "\n";
    }
};

class Stack {
private:
    DynamicArray arr;
    string       name;
public:
    Stack(const string& n = "Stack") : arr(8), name(n) {}

    void push(int v) {
        arr.push(v);
        cout << "[STACK:" << name << "] Pushed " << v << "\n";
    }
    int pop() {
        if (arr.isEmpty())
            throw underflow_error("Stack underflow: " + name + " is empty.");
        int top = arr[arr.getSize()-1];
        arr.pop();
        cout << "[STACK:" << name << "] Popped " << top << "\n";
        return top;
    }
    int  peek()    const { return arr.get(arr.getSize()-1); }
    bool isEmpty() const { return arr.isEmpty();            }
    int  size()    const { return arr.getSize();            }

    void display() const {
        cout << "[STACK:" << name << "] top -> [";
        for (int i=arr.getSize()-1; i>=0; i--) {
            cout << arr.get(i);
            if (i > 0) cout << ",";
        }
        cout << "]\n";
    }
};

class Queue {
private:
    DynamicArray arr;
    int          front_;
    string       name;
public:
    Queue(const string& n = "Queue") : arr(8), front_(0), name(n) {}

    void enqueue(int v) {
        arr.push(v);
        cout << "[QUEUE:" << name << "] Enqueued " << v << "\n";
    }
    int dequeue() {
        if (isEmpty())
            throw underflow_error("Queue underflow: " + name + " is empty.");
        int val = arr.get(front_++);
        cout << "[QUEUE:" << name << "] Dequeued " << val << "\n";
        return val;
    }
    int  peek()    const { return arr.get(front_);          }
    bool isEmpty() const { return front_ >= arr.getSize();  }
    int  size()    const { return arr.getSize() - front_;   }

    void display() const {
        cout << "[QUEUE:" << name << "] front -> [";
        for (int i=front_; i<arr.getSize(); i++) {
            cout << arr.get(i);
            if (i < arr.getSize()-1) cout << ",";
        }
        cout << "] <- rear\n";
    }
};

class ContentCatalog {
private:
    map<int,string>     catalog;      
    std::queue<string>  watchQueue;   
    std::stack<string>  recentStack;  

public:
    void addContent(int id, const string& title) {
        catalog[id] = title;
        cout << "[CATALOG] Added [" << id << "] " << title << "\n";
    }
    string findByID(int id) const {
        auto it = catalog.find(id);
        return (it != catalog.end()) ? it->second : "Not found";
    }
    void addToWatchQueue(const string& t) {
        watchQueue.push(t);
        cout << "[STL QUEUE] Added: " << t << "\n";
    }
    void watchNext() {
        if (watchQueue.empty()) { cout << "[STL QUEUE] Empty.\n"; return; }
        string next = watchQueue.front();
        watchQueue.pop(); recentStack.push(next);
        cout << "[STL QUEUE] Now watching: " << next << "\n";
    }
    void showRecent() const {
        std::stack<string> tmp = recentStack;
        cout << "[STL STACK] Recently viewed (most recent first):\n";
        int i = 1;
        while (!tmp.empty()) {
            cout << "  " << i++ << ". " << tmp.top() << "\n";
            tmp.pop();
        }
    }
    void showAll() const {
        cout << "[CATALOG] " << catalog.size() << " titles:\n";
        for (const auto& p : catalog)
            cout << "  [" << p.first << "] " << p.second << "\n";
    }
};

class SearchHelper {
public:
    static void search(const string& keyword) {
        cout << "[SEARCH] By keyword: \"" << keyword << "\"\n"; }
    static void search(int contentID) {
        cout << "[SEARCH] By ID: " << contentID << "\n"; }
    static void search(const string& keyword, int year) {
        cout << "[SEARCH] \"" << keyword << "\" + year " << year << "\n"; }
    static void search(double minRating) {
        cout << "[SEARCH] Min IMDB rating: " << minRating << "+\n"; }
};

class AuthException : public exception {
    string msg;
public:
    AuthException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class StreamException : public exception {
    string msg;
public:
    StreamException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class FileException : public exception {
    string msg;
public:
    FileException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class FileManager {
private:
    const string MOVIES_FILE = "movies.txt";
    const string DOCS_FILE   = "documentaries.txt";
    const string RATINGS_FILE= "ratings.txt";
    const string USERS_FILE  = "users.txt";

    vector<string> splitLine(const string& line, char d='|') const {
        vector<string> tokens;
        stringstream ss(line); string s;
        while (getline(ss, s, d)) tokens.push_back(s);
        return tokens;
    }
    bool fileExists(const string& f) const {
        ifstream fs(f); return fs.good();
    }

public:
    void saveMovies(const vector<Movie>& movies) const {
        ofstream file(MOVIES_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open movies.txt\n"; return; }
        for (const auto& m : movies)
            file << m.getContentID() << "|" << m.getTitle() << "|"
                 << m.getLanguage()  << "|" << m.getImdbRating() << "|"
                 << m.getReleaseYear()<< "|" << m.getGenre() << "|"
                 << m.getDuration()  << "|" << m.getDirector() << "|"
                 << m.getAgeRating() << "\n";
        file.close();
        cout << "[FILE] " << movies.size() << " movies saved.\n";
    }

    void saveDocumentaries(const vector<Documentary>& docs) const {
        ofstream file(DOCS_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open documentaries.txt\n"; return; }
        for (const auto& d : docs)
            file << d.getContentID()       << "|" << d.getTitle()          << "|"
                 << d.getLanguage()        << "|" << d.getImdbRating()     << "|"
                 << d.getReleaseYear()     << "|" << d.getTopic()          << "|"
                 << d.getNarrator()        << "|" << d.getProductionHouse()<< "|"
                 << d.getDuration()        << "|" << d.getHasSubtitles()   << "\n";
        file.close();
        cout << "[FILE] " << docs.size() << " documentaries saved.\n";
    }

    void saveUsers(const vector<FreeUser>& fu,
                   const vector<PremiumUser>& pu) const {
        ofstream file(USERS_FILE);
        if (!file.is_open()) return;
        for (const auto& u : fu)
            file << "FREE|" << u.getUserID() << "|"
                 << u.getName() << "|" << u.getEmail() << "|hidden\n";
        for (const auto& u : pu)
            file << "PREMIUM|" << u.getUserID() << "|"
                 << u.getName() << "|" << u.getEmail()
                 << "|hidden|" << u.getPlan() << "\n";
        cout << "[FILE] Users saved.\n";
    }

    void appendRating(const Rating& r) const {
        ofstream file(RATINGS_FILE, ios::app);
        if (!file.is_open()) return;
        file << r.getContentID() << "|" << r.getUserID() << "|"
             << r.getScore()     << "|" << r.getReview() << "|"
             << r.getDatePosted()<< "\n";
        cout << "[FILE] Rating appended.\n";
    }

    vector<Movie> loadMovies() const {
        vector<Movie> mv; ifstream file(MOVIES_FILE);
        if (!file.is_open()) {
            cout << "[FILE] movies.txt not found. Starting fresh.\n";
            return mv;
        }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 9) continue;
            try { mv.push_back(Movie(stoi(t[0]),t[1],t[2],stod(t[3]),
                                     stoi(t[4]),t[5],stod(t[6]),t[7],t[8])); }
            catch (...) { cerr << "[FILE] Skipping malformed line.\n"; }
        }
        file.close();
        cout << "[FILE] Loaded " << mv.size() << " movies.\n";
        return mv;
    }

    vector<Documentary> loadDocumentaries() const {
        vector<Documentary> dv; ifstream file(DOCS_FILE);
        if (!file.is_open()) {
            cout << "[FILE] documentaries.txt not found. Starting fresh.\n";
            return dv;
        }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 10) continue;
            try { dv.push_back(Documentary(stoi(t[0]),t[1],t[2],stod(t[3]),
                                            stoi(t[4]),t[5],t[6],t[7],
                                            stod(t[8]),stoi(t[9]))); }
            catch (...) {}
        }
        file.close();
        cout << "[FILE] Loaded " << dv.size() << " documentaries.\n";
        return dv;
    }

    vector<Rating> loadRatings() const {
        vector<Rating> rv; ifstream file(RATINGS_FILE);
        if (!file.is_open()) return rv;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 5) continue;
            try { rv.push_back(Rating(stoi(t[0]),stoi(t[1]),
                                      stod(t[2]),t[3],t[4])); }
            catch (...) {}
        }
        file.close();
        cout << "[FILE] Loaded " << rv.size() << " ratings.\n";
        return rv;
    }

    void checkFiles() const {
        cout << "\n  === Data File Status ===\n";
        for (const auto& f : {MOVIES_FILE,DOCS_FILE,RATINGS_FILE,USERS_FILE})
            cout << "  " << (fileExists(f) ? "[EXISTS] " : "[MISSING]") << f << "\n";
        cout << "  ========================\n";
    }
};

class Platform;
class Analytics { public: static void showReport(const Platform& p); };

class AdminUser : public User, public StreamingEngine {
private:
    string     adminLevel;
    int        currentBitrate;
    static int adminCount;        

public:
    AdminUser(int id, const string& n, const string& e,
              const string& p, const string& level)
        : User(id, n, e, p),
          StreamingEngine("Admin-Server", 50),
          adminLevel(level), currentBitrate(50000) {
        adminCount++;
        cout << "[ADMIN] Account created: " << n
             << " (Level: " << level << ")\n";
    }
    ~AdminUser() { adminCount--; }

    static int getAdminCount() { return adminCount; }

    string getAdminLevel() const { return adminLevel; }

    // User pure virtual overrides
    string getAccountType() const override { return "Admin(" + adminLevel + ")"; }
    bool   canDownload()    const override { return true; }
    bool   canWatchHD()     const override { return true; }
    int    getScreenLimit() const override { return 999;  }

    void displayProfile() const override {
        cout << "\n  ===== ADMIN PROFILE =====\n";
        cout << "  Name   : " << getName()         << "\n";
        cout << "  Level  : " << adminLevel        << "\n";
        cout << "  Server : " << getServerRegion() << "\n";
        cout << "  Buffer : " << getBufferSize()   << "MB\n";
        cout << "  =========================\n";
    }
    void showWelcome() const override {
        cout << "[ADMIN] Welcome " << getName()
             << "! Level: " << adminLevel << "\n";
    }

    string getQuality()  const override { return "Unrestricted (Admin)"; }
    int    getBitrate()  const override { return currentBitrate;         }
    void stream()        const override {
        cout << "[ADMIN STREAM] Unrestricted at "
             << currentBitrate << "kbps\n";
    }
    void adjustBandwidth(int k) override {
        currentBitrate = k;
        cout << "[ADMIN] Bandwidth set to " << k << "kbps\n";
    }

    void banUser(int id) const {
        cout << "[ADMIN] User#" << id << " banned by " << getName() << "\n";
    }
    void addContent(const string& title) const {
        cout << "[ADMIN] \"" << title << "\" added by " << getName() << "\n";
    }
};
int AdminUser::adminCount = 0;

class Platform {
    friend class Analytics;          

    static int totalUsers;

private:
    vector<Movie>       movies;
    vector<Series>      series;
    vector<Documentary> docs;
    vector<Rating>      ratings;
    vector<FreeUser>    freeUsers;
    vector<PremiumUser> premUsers;

    SDStream      sdEngine;
    HDStream      hdEngine;
    UltraHDStream uhdEngine;
    FileManager   fm;

    User* currentUser;
    bool  loggedIn;

    WatchHistory<Movie>       movieHist;
    WatchHistory<Documentary> docHist;
    int nextID;

    StreamingEngine* selectEngine() {
        if (!currentUser) return &sdEngine;
        string t = currentUser->getAccountType();
        if (t.find("Ultra")   != string::npos) return &uhdEngine;
        if (t.find("Premium") != string::npos) return &hdEngine;
        return &sdEngine;
    }

    Movie*       findMovie(int id) {
        for (auto& m : movies) if (m.getContentID()==id) return &m;
        return nullptr;
    }
    Documentary* findDoc(int id) {
        for (auto& d : docs) if (d.getContentID()==id) return &d;
        return nullptr;
    }
    bool emailExists(const string& e) const {
        for (const auto& u : freeUsers) if (u.getEmail()==e) return true;
        for (const auto& u : premUsers) if (u.getEmail()==e) return true;
        return false;
    }
    void line(char c='-', int n=45) const { cout << string(n,c) << "\n"; }

public:
    Platform() : currentUser(nullptr), loggedIn(false),
                 movieHist("Guest"), docHist("Guest"), nextID(100) {
        cout << "\n[PLATFORM] Initialising CineStream...\n";
        movies  = fm.loadMovies();
        docs    = fm.loadDocumentaries();
        ratings = fm.loadRatings();
        seedCatalog();
        cout << "[PLATFORM] Ready.\n";
    }

    ~Platform() {
        cout << "\n[PLATFORM] Saving all data...\n";
        fm.saveMovies(movies);
        fm.saveDocumentaries(docs);
        fm.saveUsers(freeUsers, premUsers);
        cout << "[PLATFORM] Goodbye!\n";
    }

    void seedCatalog() {
        if (!movies.empty() || !docs.empty()) return;
        cout << "[PLATFORM] First run — seeding catalog...\n";
        movies.push_back(Movie(1,"Inception",    "English",8.8,2010,"Sci-Fi",  148,"C. Nolan","PG-13"));
        movies.push_back(Movie(2,"Dark Knight",  "English",9.0,2008,"Action",  152,"C. Nolan","PG-13"));
        movies.push_back(Movie(3,"Parasite",     "Korean", 8.5,2019,"Thriller",132,"B. Joon", "R"    ));
        movies.push_back(Movie(4,"Interstellar", "English",8.6,2014,"Sci-Fi",  169,"C. Nolan","PG-13"));
        movies.push_back(Movie(5,"The Godfather","English",9.2,1972,"Crime",   175,"Coppola", "R"    ));

        // Series with episodes
        Series bb(6,"Breaking Bad","English",9.5,2008,"Drama",5,"Completed");
        bb.addEpisode(Episode(61,"Pilot","English",8.9,2008,1,1,58,"Walt's transformation begins."));
        bb.addEpisode(Episode(62,"Cat's in the Bag","English",8.7,2008,1,2,48,"Cleaning up the mess."));
        series.push_back(bb);

        docs.push_back(Documentary(10,"Planet Earth II",  "English",9.5,2016,"Nature","D. Attenborough","BBC",    360,true));
        docs.push_back(Documentary(11,"Making a Murderer","English",8.6,2015,"Crime", "Various",         "Netflix",600,true));
    }

    static int getTotalUsers() { return totalUsers; }

    bool registerFree(const string& n, const string& e,
                      const string& p) {
        if (emailExists(e)) { cout<<"[AUTH] Email already registered.\n"; return false; }
        freeUsers.push_back(FreeUser(nextID++, n, e, p));
        totalUsers++;
        cout << "[AUTH] Free account created: " << n
             << " | Total users: " << totalUsers << "\n";
        return true;
    }

    bool registerPremium(const string& n, const string& e,
                         const string& p, const string& plan) {
        if (emailExists(e)) { cout<<"[AUTH] Email already registered.\n"; return false; }
        premUsers.push_back(PremiumUser(nextID++, n, e, p, plan));
        totalUsers++;
        cout << "[AUTH] Premium(" << plan << ") account: " << n
             << " | Total users: " << totalUsers << "\n";
        return true;
    }

    bool login(const string& e, const string& p) {
        for (auto& u : freeUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                movieHist=WatchHistory<Movie>(u.getName());
                docHist=WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        for (auto& u : premUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                movieHist=WatchHistory<Movie>(u.getName());
                docHist=WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        cout << "[AUTH] Invalid email or password.\n";
        return false;
    }

    void logout() {
        if (!loggedIn) { cout << "Not logged in.\n"; return; }
        cout << "[AUTH] Goodbye, " << currentUser->getName() << "!\n";
        currentUser=nullptr; loggedIn=false;
    }

    void browseCatalog() const {
        line('=');
        cout << "  MOVIES (" << movies.size() << ")\n"; line('=');
        for (const auto& m : movies) m.display();
        line('-');
        cout << "  SERIES (" << series.size() << ")\n"; line('-');
        for (const auto& s : series) s.display();
        line('-');
        cout << "  DOCUMENTARIES (" << docs.size() << ")\n"; line('-');
        for (const auto& d : docs) d.display();
        line('=');
    }

    void searchContent(const string& kw) const {
        cout << "\n--- Search: \"" << kw << "\" ---\n";
        bool found = false;
        for (const auto& m : movies)
            if (m.getTitle().find(kw) != string::npos) {
                cout << "[Movie] " << m.getTitle()
                     << " | IMDB:" << m.getImdbRating() << "\n";
                found = true;
            }
        for (const auto& d : docs)
            if (d.getTitle().find(kw) != string::npos) {
                cout << "[Doc] " << d.getTitle()
                     << " | IMDB:" << d.getImdbRating() << "\n";
                found = true;
            }
        if (!found) cout << "No results found.\n";
    }

    void watchMovie(int id) {
        if (!loggedIn) { cout << "Please login first.\n"; return; }
        Movie* m = findMovie(id);
        if (!m) { cout << "Movie not found.\n"; return; }
        StreamingEngine* engine = selectEngine();  
        line('=');
        m->play();
        engine->stream();
        engine->showStreamInfo();
        line('=');
        movieHist.add(*m);
        if (currentUser->getAccountType() == "Free")
            if (auto* fu = dynamic_cast<FreeUser*>(currentUser))
                fu->watchContent((int)m->getDuration());
    }

    void watchDoc(int id) {
        if (!loggedIn) { cout << "Please login first.\n"; return; }
        Documentary* d = findDoc(id);
        if (!d) { cout << "Documentary not found.\n"; return; }
        line('='); d->play(); selectEngine()->stream(); line('=');
        docHist.add(*d);
    }

    void rateContent(int cid, double score, const string& review) {
        if (!loggedIn) { cout << "Please login first.\n"; return; }
        Rating r(cid, currentUser->getUserID(), score, review, "2025-01-01");
        ratings.push_back(r); fm.appendRating(r);
        cout << "[RATING] Thank you! "; r.displayStars();
    }

    void showRatings(int cid) const {
        cout << "\n--- Ratings for Content #" << cid << " ---\n";
        bool f = false;
        for (const auto& r : ratings)
            if (r.getContentID()==cid) { r.display(); f=true; }
        if (!f) cout << "No ratings yet.\n";
    }

    void showProfile()  const {
        if (!loggedIn) { cout<<"Login first.\n"; return; }
        currentUser->displayProfile();
    }
    void showHistory()  const { movieHist.display(); docHist.display(); }
    void showFiles()    const { fm.checkFiles(); }
    bool isLoggedIn()   const { return loggedIn;     }
    User* getUser()     const { return currentUser;  }
};
int Platform::totalUsers = 0;
void Analytics::showReport(const Platform& p) {
    cout << "\n+========================================+\n";
    cout << "|     ANALYTICS REPORT (Friend Class)    |\n";
    cout << "+========================================+\n";
    cout << "| Movies       : " << p.movies.size()    << "\n";
    cout << "| Series       : " << p.series.size()    << "\n";
    cout << "| Documentaries: " << p.docs.size()      << "\n";
    cout << "| Free Users   : " << p.freeUsers.size() << "\n";
    cout << "| Premium Users: " << p.premUsers.size() << "\n";
    cout << "| Total Ratings: " << p.ratings.size()   << "\n";
    if (!p.ratings.empty()) {
        double total = 0;
        const Rating* best = &p.ratings[0];
        for (const auto& r : p.ratings) {
            total += r.getScore();
            if (r > *best) best = &r;   // operator> used
        }
        cout << "| Avg Rating   : " << total/p.ratings.size() << "/5\n";
        cout << "| Best Content : #" << best->getContentID()
             << " (" << best->getScore() << "/5)\n";
    }
    cout << "+========================================+\n";
}

void safeLogin(Platform& p, const string& e, const string& pw) {
    try {
        if (e.empty() || pw.empty())
            throw AuthException("Email and password cannot be empty.");
        if (pw.length() < 4)
            throw AuthException("Password too short (min 4 chars).");
        if (!p.login(e, pw))
            throw AuthException("Invalid credentials for: " + e);
        cout << "[AUTH] Login successful.\n";
    }
    catch (const AuthException& ex) { cerr << "[AUTH ERR] " << ex.what() << "\n"; }
    catch (const exception& ex)     { cerr << "[ERR] "      << ex.what() << "\n"; }
}

void safeRegister(Platform& p, const string& n,
                  const string& e, const string& pw) {
    try {
        if (n.empty())                    throw AuthException("Name cannot be empty.");
        if (e.find('@') == string::npos)  throw AuthException("Invalid email: " + e);
        if (pw.length() < 4)              throw AuthException("Password too short.");
        p.registerFree(n, e, pw);
    }
    catch (const AuthException& ex) { cerr << "[REG ERR] " << ex.what() << "\n"; }
}

void safeWatch(Platform& p, int id) {
    try {
        if (id <= 0)          throw StreamException("Invalid movie ID: " + to_string(id));
        if (!p.isLoggedIn())  throw AuthException("Must be logged in to watch.");
        p.watchMovie(id);
    }
    catch (const AuthException& ex)  { cerr << "[AUTH ERR] "   << ex.what() << "\n"; }
    catch (const StreamException& ex){ cerr << "[STREAM ERR] " << ex.what() << "\n"; }
}

void runDemo(Platform& p) {
    cout << "\n\n";

    cout << " STATIC DATA & MEMBER FUNCTIONS\n";
    cout << "[STATIC] AdminUser::getAdminCount()     = "
         << AdminUser::getAdminCount() << " (called on CLASS)\n";
    cout << "[STATIC] Platform::getTotalUsers()      = "
         << Platform::getTotalUsers() << "\n";

    cout << " OPERATOR OVERLOADING\n";
    Rating r1(1,1,4.5,"Brilliant film!","2025-01-01");
    Rating r2(1,2,3.0,"It was average.","2025-01-02");
    Rating r3(1,3,4.8,"Near perfect!","2025-01-03");
    cout << "r1: " << r1 << "\n";   // operator<<
    cout << "r2: " << r2 << "\n";
    cout << "r1 > r2 ? " << (r1 > r2 ? "Yes" : "No") << "\n"; 
    cout << "r2 < r3 ? " << (r2 < r3 ? "Yes" : "No") << "\n";  
    cout << "r1 == r3? " << (r1 == r3 ? "Yes" : "No") << "\n"; 
    Rating avg = r1 + r2;  // operator+
    cout << "r1 + r2 (averaged): "; avg.displayStars();

    cout <<" FUNCTION OVERLOADING\n";
    SearchHelper::search("Inception");       
    SearchHelper::search(1);                  
    SearchHelper::search("Nolan", 2010);     
    SearchHelper::search(8.5);                

    cout << " FRIEND CLASS\n";
    Analytics::showReport(p);

    cout << " MULTIPLE INHERITANCE\n";
    AdminUser admin(999,"SuperAdmin","admin@cine.com","admin1234","Super");
    admin.showWelcome();
    admin.displayProfile();
    User* uPtr = &admin;             
    StreamingEngine* sPtr = &admin;  
    cout << "\n[via User*]            ";
    cout << "Account: " << uPtr->getAccountType() << "\n";
    cout << "[via StreamingEngine*] "; sPtr->stream();
    cout << "[STATIC] Admin count: " << AdminUser::getAdminCount() << "\n";
    admin.banUser(42);
    admin.addContent("Oppenheimer");

    cout << " TEMPLATES\n";
    WatchHistory<Movie>       mh("DemoUser");
    WatchHistory<Documentary> dh("DemoUser");
    cout << "WatchHistory<Movie> and WatchHistory<Documentary>"
         << " — same template, two types.\n";

    MonthlyPlan mp; AnnualPlan ap; FamilyPlan fp;
    Subscription<MonthlyPlan> s1("ali@x.com", mp, 30);
    Subscription<AnnualPlan>  s2("sara@x.com",ap, 365);
    Subscription<FamilyPlan>  s3("zaid@x.com",fp, 30);
    s1.display(); s2.display(); s3.display();
    s1.renew(); s2.cancel();

    cout << " DYNAMIC ARRAY + COPY CONSTRUCTOR\n";
    DynamicArray a1(4);
    a1.push(10); a1.push(20); a1.push(30);
    a1.display();
    DynamicArray a2 = a1;  
    a2.push(40);
    cout << "a1 (unchanged after modifying a2): "; a1.display();
    cout << "a2 (independent deep copy):        "; a2.display();
    DynamicArray a3(2); a3 = a1;
    cout << "a3 (copy assigned from a1):        "; a3.display();
    cout << "a1[1] via operator[]: " << a1[1] << "\n";
    try { cout << a1[99]; }
    catch (const out_of_range& e) { cerr << "[EXCEPTION] " << e.what() << "\n"; }

    cout << "  EXCEPTION HANDLING\n";
    cout << "\n[Test 1] Login with empty fields:\n";
    safeLogin(p, "", "");
    cout << "\n[Test 2] Register with invalid email:\n";
    safeRegister(p, "User", "notemail", "pass1234");
    cout << "\n[Test 3] Register with short password:\n";
    safeRegister(p, "User", "u@x.com", "ab");
    cout << "\n[Test 4] Watch with invalid ID:\n";
    safeWatch(p, -1);
    cout << "\n[Test 5] Watch without login:\n";
    safeWatch(p, 1);
    cout << "\n[Test 6] Valid registration + login + watch:\n";
    safeRegister(p, "Demo User", "demo@x.com", "pass1234");
    safeLogin(p, "demo@x.com", "pass1234");
    if (p.isLoggedIn()) { safeWatch(p, 1); p.logout(); }
    cout << "\n[Test 7] DynamicArray out-of-range (already shown above)\n";

    cout << "  STACK (LIFO) using DynamicArray\n";
    Stack st("ViewHistory");
    st.push(101); st.push(202); st.push(303);
    st.display();
    cout << "Peek (top): " << st.peek() << "\n";
    st.pop(); st.pop(); st.display();
    try { Stack empty("Empty"); empty.pop(); }
    catch (const underflow_error& e) { cerr << "[EXCEPTION] " << e.what() << "\n"; }

    cout << " QUEUE (FIFO) using DynamicArray\n";
    Queue q("StreamBuffer");
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    q.display();
    q.dequeue(); q.dequeue(); q.display();
    try { Queue empty("Empty"); empty.dequeue(); }
    catch (const underflow_error& e) { cerr << "[EXCEPTION] " << e.what() << "\n"; }

    cout << "  STL CONTAINERS (map, queue, stack)\n";
    ContentCatalog cat;
    cat.addContent(1,"Inception");
    cat.addContent(2,"Dark Knight");
    cat.addContent(10,"Planet Earth II");
    cat.showAll();
    cout << "Find ID 2 : " << cat.findByID(2)  << "\n";
    cout << "Find ID 99: " << cat.findByID(99) << "\n";
    cat.addToWatchQueue("Inception");
    cat.addToWatchQueue("Interstellar");
    cat.addToWatchQueue("Parasite");
    cat.watchNext(); cat.watchNext();
    cat.showRecent();

}

void clr() { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); }

void userMenu(Platform& p) {
    int c;
    while (p.isLoggedIn()) {
        cout << "\n+--------------------------------------+\n";
        cout << "| [1] Browse       [2] Search          |\n";
        cout << "| [3] Watch Movie  [4] Watch Doc       |\n";
        cout << "| [5] Rate         [6] View Ratings    |\n";
        cout << "| [7] History      [8] Profile         |\n";
        cout << "| [9] Files        [0] Logout          |\n";
        cout << "+--------------------------------------+\n";
        cout << "Choice: "; cin >> c;
        if      (c==1) p.browseCatalog();
        else if (c==2) {
            string kw; cout<<"Keyword: "; clr(); getline(cin,kw);
            p.searchContent(kw); }
        else if (c==3) {
            int id; p.browseCatalog();
            cout<<"Movie ID: "; cin>>id; p.watchMovie(id); }
        else if (c==4) {
            int id; p.browseCatalog();
            cout<<"Doc ID: "; cin>>id; p.watchDoc(id); }
        else if (c==5) {
            int id; double s; string r;
            cout<<"Content ID: "; cin>>id;
            cout<<"Score(1-5): "; cin>>s;
            cout<<"Review: "; clr(); getline(cin,r);
            p.rateContent(id,s,r); }
        else if (c==6) {
            int id; cout<<"Content ID: "; cin>>id;
            p.showRatings(id); }
        else if (c==7) p.showHistory();
        else if (c==8) p.showProfile();
        else if (c==9) p.showFiles();
        else if (c==0) p.logout();
        else cout << "Invalid choice.\n";
    }
}

int main() {
    Platform platform;
    int choice;

    while (true) {
        cout << "\n+======================================+\n";
        cout << "|         CINESTREAM PLATFORM          |\n";
        cout << "+======================================+\n";
        cout << "|  1. Register (Free Account)          |\n";
        cout << "|  2. Register (Premium Account)       |\n";
        cout << "|  3. Login                            |\n";
        cout << "|  4. Browse Catalog                   |\n";
        cout << "|  5. [DEMO] All OOP Concepts          |\n";
        cout << "|  0. Exit                             |\n";
        cout << "+======================================+\n";
        cout << "Choice: "; cin >> choice;

        if (choice == 1) {
            string n, e, p;
            cout << "\n-- Free Registration --\n";
            cout << "Name: ";     clr(); getline(cin,n);
            cout << "Email: ";          getline(cin,e);
            cout << "Password: ";       getline(cin,p);
            safeRegister(platform, n, e, p);
        }
        else if (choice == 2) {
            string n, e, p, pl;
            cout << "\n-- Premium Registration --\n";
            cout << "Name: ";                    clr(); getline(cin,n);
            cout << "Email: ";                          getline(cin,e);
            cout << "Password: ";                       getline(cin,p);
            cout << "Plan (Basic/Standard/Ultra): ";    getline(cin,pl);
            if (pl!="Basic"&&pl!="Standard"&&pl!="Ultra") pl="Standard";
            platform.registerPremium(n, e, p, pl);
        }
        else if (choice == 3) {
            string e, p;
            cout << "\n-- Login --\n";
            cout << "Email: ";    clr(); getline(cin,e);
            cout << "Password: ";       getline(cin,p);
            safeLogin(platform, e, p);
            if (platform.isLoggedIn()) userMenu(platform);
        }
        else if (choice == 4) platform.browseCatalog();
        else if (choice == 5) runDemo(platform);
        else if (choice == 0) { cout << "Exiting CineStream...\n"; return 0; }
        else cout << "Invalid choice.\n";
    }
}