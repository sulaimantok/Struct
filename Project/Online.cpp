#include "Online.h"

Online::pembayaran() {
}
Online::~pembayaran() {
};
LinkedList Online::XMLToLinkedList() {
	OperationFile File2("pembayaran.xml");
	string isifile = File2.getFile();
	LinkedList LinkedList1;
	vector<string> jenis = File2.getData(isifile, "jenis");
	vector<string> harga = File2.getData(isifile, "harga");
	vector<string> tanggal = File2.getData(isifile, "tanggal");
	vector<string> waktu = File2.getData(isifile, "waktu");
	vector<string> info = File2.getData(isifile, "info");
	vector<string> metode = File2.getData(isifile, "metode");
	vector<linkedlist> data;

	for (int i = 0; i < jenis.size(); i++) {
		data.push_back(linkedlist());
		data[i].jenis = jenis[i];
		data[i].harga = harga[i];
		data[i].tanggal = tanggal[i];
		data[i].waktu = waktu[i];
		data[i].info = info[i];
		data[i].metode = metode[i];
		LinkedList1.AddLast(data[i].jenis, data[i].harga, data[i].tanggal, data[i].waktu, data[i].info,data[i].metode);
	}
	return LinkedList1;
}
void Online::SaveToXML(string jenis, string harga, string tanggal, string waktu, string info,string metode) {
	OperationFile File2("/home/sulaiman/ngoding/c++_C/Struktur/Project/pembayaran.xml");
	string isiFile = File2.getFile();
	size_t location=isiFile.find("</trasaksi>");
	string input = "\n\t<jenis>" + jenis + "</jenis>\n\t<Harga>" + harga + "</Harga>\n\t<tanggal>" + tanggal + "</tanggal>\n\t<waktu>" + waktu + "</waktu>\n\t<info>" + info + "</info>\n\t<metode>" + metode + "</metode>";
	if(location!=string::npos) isiFile.insert(location - 1, input);
	else cout << "</trasaksi> tidak Ditemukan\n";
	File2.OverwriteToFile(isiFile);
}