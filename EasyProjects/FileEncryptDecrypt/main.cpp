#include <cctype>
#include <fstream>
#include <string>

using namespace std;

void CRYPT(string character, string word, string text, string result, int index, int shift, int choice){
    ifstream random("random.txt");
    while (getline(random, character)){
       text += character;
    }
    random.close();

    for (char c : text)
    {
        if(c == ' ' || c == '.' || c == ','){
            result += c;
            continue;
        }
        index = word.find((char)tolower(c));
        if (index + shift > 25 && choice == 1) {
            index = (index + shift) - 26;
            result += word[index];
            continue;
        }
        if (index - shift < 0 && choice == 2) {
            index = 26 + index - shift;
            result += word[index];
            continue;
        }
        result += (choice == 1) ? word[index + shift] : word[index - shift];
    }

    ofstream write("random.txt");
    write << result;
    write.close();
}

int main(){
    string word = "abcdefghijklmnopqrstuvwxyz";
    string character, text, result;
    int index{0};
    int shift{5};
    CRYPT(character, word, text, result, index, shift, 1);
    character = "", text = "", result = "", index = 0;
    CRYPT(character, word, text, result, index, shift, 2);
    return 0;
}







// #include <cctype>
// #include <fstream>
// #include <string>

// using namespace std;


// void ENCRYPT(string character, string word, string text, string result, int index, int shift){
//     ifstream random("random.txt");
//     while (getline(random, character)){
//        text += character;
//     }
//     random.close();

//     for (char c : text)
//     {
//         if(c == ' ' || c == '.' || c == ','){
//             result += c;
//             continue;
//         }
//         index = word.find((char)tolower(c));
//         if (index + shift > 25)
//         {
//             index = (index + shift) - 26;
//             result += word[index];
//             continue;
//         }
//         result += word[index + shift];
//     }
//     ofstream write("random.txt");
//     write << result;
//     write.close();
// }


// void DECRYPT(string character, string word, string text, string result, int index, int shift){
//     ifstream random("random.txt");
//     while (getline(random, character))
//     {   text += character;

//     }
//     random.close();
//     for (char c : text)
//     {
//         if(c == ' ' || c == '.' || c == ','){
//             result += c;
//             continue;
//         }
//         index = word.find((char)tolower(c));
//         if (index - shift < 0) {
//             result += word[26 + index - shift];
//         }
//         else{
//             result += word[index - shift];
//         }
//     }
//     ofstream write("random.txt");
//     write << result;
//     write.close();
// }


// int main(){
//     string word = "abcdefghijklmnopqrstuvwxyz";
//     string character, text, result, re_result;
//     int index{0};
//     int shift{8};
//     ENCRYPT(character, word, text, result, index, shift);
//     character = "", text = "", result = "", index = 0;
//     DECRYPT(character, word, text, result, index, shift);
//     return 0;
// }













/*
ifstream random("random.txt");
while (getline(random, character))
{   text += character;

}
random.close();
for (char c : text)
{
    if(c == ' ' || c == '.' || c == ','){
        result += c;
        continue;
    }
    index = word.find((char)tolower(c));
    if (index - shift < 0) {
        result += word[26 + index - shift];
    }
    else{
        result += word[index - shift];
    }
}
cout << result << endl;
 */


/*
Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc,
 */


/*
qtwjr nuxzr itqtw xny frjy, htsxjhyjyzjw finunxhnsl jqny. fjsjfs htrrtit qnlzqf jljy itqtw. fjsjfs rfxxf. hzr xthnnx sfytvzj ujsfyngzx jy rflsnx inx ufwyzwnjsy rtsyjx, sfxhjyzw wninhzqzx rzx. itsjh vzfr kjqnx, zqywnhnjx sjh, ujqqjsyjxvzj jz, uwjynzr vznx, xjr. szqqf htsxjvzfy rfxxf vznx jsnr. itsjh ujij ozxyt, kwnslnqqf ajq, fqnvzjy sjh, azquzyfyj jljy, fwhz. ns jsnr ozxyt, wmtshzx zy, nrujwinjy f, ajsjsfynx anyfj, ozxyt. szqqfr inhyzr kjqnx jz ujij rtqqnx uwjynzr. nsyjljw ynshnizsy. hwfx ifungzx. anafrzx jqjrjsyzr xjrujw snxn. fjsjfs azquzyfyj jqjnkjsi yjqqzx. fjsjfs qjt qnlzqf, utwyynytw jz, htsxjvzfy anyfj, jqjnkjsi fh, jsnr. fqnvzfr qtwjr fsyj, ifungzx ns, anajwwf vznx, kjzlnfy f, yjqqzx. umfxjqqzx anajwwf szqqf zy rjyzx afwnzx qftwjjy. vznxvzj wzywzr. fjsjfs nrujwinjy. jynfr zqywnhnjx snxn ajq fzlzj. hzwfgnyzw zqqfrhtwujw zqywnhnjx snxn. sfr jljy izn. jynfr wmtshzx. rfjhjsfx yjruzx, yjqqzx jljy htsinrjsyzr wmtshzx, xjr vzfr xjrujw qngjwt, xny frjy finunxhnsl xjr sjvzj xji nuxzr. sfr vzfr szsh, gqfsiny ajq, qzhyzx uzqansfw, mjsiwjwny ni, qtwjr. rfjhjsfx sjh tint jy fsyj ynshnizsy yjruzx. itsjh anyfj xfunjs zy qngjwt ajsjsfynx kfzhngzx. szqqfr vznx fsyj. jynfr xny frjy twhn jljy jwtx kfzhngzx ynshnizsy. iznx qjt. xji kwnslnqqf rfzwnx xny frjy sngm. itsjh xtifqjx xflnyynx rflsf. xji htsxjvzfy, qjt jljy gngjsizr xtifqjx, fzlzj ajqny hzwxzx szsh,
 */

