#include "Online.h"

Online::Online() {
}
Online::~Online() {
};
LinkedList Online::XMLToLinkedList() {
	OperationFile File2("Pembayaran.xml");
	string isifile = File2.getFile();
	LinkedList LinkedList1;
	vector<string> datajenis = File2.getData(isifile, "jenis");
	vector<string> datametode = File2.getData(isifile, "metode");
	vector<string> datatanggal = File2.getData(isifile, "tanggal");
	vector<string> datawaktu = File2.getData(isifile, "waktu");
	vector<string> dataharga = File2.getData(isifile, "harga");
	vector<linkedlist> data;

	for (int i = 0; i < datajenis.size(); i++) {
		data.push_back(linkedlist());
		data[i].jenis = datajenis[i];
		data[i].metode = datametode[i];
		data[i].tanggal = datatanggal[i];
		data[i].waktu = datawaktu[i];
		data[i].harga = dataharga[i];
		LinkedList1.AddLast(data[i].jenis, data[i].metode, data[i].tanggal, data[i].waktu, data[i].harga);
	}
	return LinkedList1;
}
void Online::SaveToXML(string jenis, string metode, string tanggal, string waktu, string harga) {
	OperationFile File2("Pembayaran.xml");
	string isiFile = File2.getFile();
	size_t location=isiFile.find("</Online>");
	string input = "\n\t<transaksi>\n\t\t<jenis>" + jenis + "</jenis>\n\t\t<metode>" + metode + "</metode>\n\t\t<tanggal>" + tanggal + "</tanggal>\n\t\t<waktu>" + waktu + "</waktu>\n\t\t<harga>" + harga + "</harga>\n\t</transaksi>";
	if(location!=string::npos) isiFile.insert(location - 1, input);
	else cout << "</Online> tidak Ditemukan\n";
	File2.OverwriteToFile(isiFile);
}