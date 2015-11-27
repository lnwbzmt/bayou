#include "../inc/data_classes.h"

IdTuple::IdTuple(int csn, string sname, int ts)
{
    csn_ = csn;
    s_name_ = sname;
    accept_ts_ = ts;
}

bool IdTuple::operator<(const IdTuple &t2) const {
    if(this->csn_<t2.csn_)
        return true;
    else if(this->csn_>t2.csn_)
        return false;
    else if(this->csn_==t2.csn_)
    {
        if(this->s_name_.length()<t2.s_name_.length())
            return true;
        else if(this->s_name_.length() > t2.s_name_.length())
            return false;
        else if(this->s_name_.length()== t2.s_name_.length())
        {
            if(this->accept_ts_<t2.accept_ts_)
                return true;
            else
                return false;
        }
    }
}
bool IdTuple::operator==(const IdTuple &t2) const {
    return this->csn_==t2.csn_ && this->s_name_.length()==t2.s_name_.length() && this->accept_ts_==t2.accept_ts_;
}
bool IdTuple::operator<=(const IdTuple &t2) const {
    return ((*this) == t2 || (*this) < t2);
}
bool IdTuple::operator>(const IdTuple &t2) const {
    return !((*this) <= t2 );
}
bool IdTuple::operator>=(const IdTuple &t2) const {
    return !((*this) < t2 );
}

int IdTuple::get_csn(){
    return csn_;
}
int IdTuple::get_accept_ts(){
    return accept_ts_;
}
string IdTuple::get_sname(){
    return s_name_;
}
string IdTuple::as_string(){
    string m;
    m+=to_string(csn_)+kInternalWriteDelim;
    m+=s_name_+kInternalWriteDelim;
    m+=to_string(accept_ts_);
    return m;
}

/////////////////////////////////////////////////////////////////

Command::Command(string a, string b, string c)
{
    type_ = a;
    song_ = b;
    url_ = c;
}
Command::Command(string a, string b)
{
    type_ = a;
    song_ = b;
}
string Command::as_string(){
    string m;
    m+=type_+kInternalWriteDelim;
    m+=song_+kInternalWriteDelim;
    m+=url_;
    return m;
}

string Command::get_type(){
    return type_;
}
string Command::get_song(){
    return song_;
}
string Command::get_url(){
    return url_;
}