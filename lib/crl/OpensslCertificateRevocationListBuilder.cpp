#include "br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder.h"
#include <libcryptosec/certificate/CertificateRevocationListBuilder.h>
#include "util/Util.h"

// FIXME: find a way to make this global variable unnecessary
// (i.e, fix Util::getInstance in 64 bit machines)
CertificateRevocationListBuilder* certInstance;

jlong Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1init__(JNIEnv* env, jobject obj)
{
	certInstance = new CertificateRevocationListBuilder();
	return (jlong) certInstance;
}

jlong Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1init__Ljava_lang_String_2(JNIEnv* env, jobject obj, jstring _crlPemEncoded)
{
	std::string crlPemEncoded = Util::jstringToString(env, _crlPemEncoded);

	try
	{
		CertificateRevocationListBuilder* builder = new CertificateRevocationListBuilder(crlPemEncoded);
		return (jlong)builder;
	}
	catch(EncodeException& ex)
	{
		Util::throwNewException(env, "EncodeException", ex.getMessage());
	}

}

jlong Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1init___3B(JNIEnv* env, jobject obj, jbyteArray _crlDerEncoded)
{
	ByteArray data = Util::jbytearrayToByteArray(env, _crlDerEncoded);
	try
	{
		CertificateRevocationListBuilder* builder = new CertificateRevocationListBuilder(data);
		return (jlong)builder;
	}
	catch(EncodeException& ex)
	{
		Util::throwNewException(env, "EncodeException", ex.getMessage());
	}
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setIssuer(JNIEnv* env, jobject obj, jlong _rdnSequenceReference)
{
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	RDNSequence* rdnSequence = (RDNSequence*)_rdnSequenceReference;
	try
	{
		builder->setIssuer(*rdnSequence);
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
	}
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1addRevokedCertificate(JNIEnv* env, jobject obj, jlong _reference)
{
	RevokedCertificate* revokedCertificate = (RevokedCertificate*)_reference;
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	try
	{
		builder->addRevokedCertificate(*revokedCertificate);
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
	}
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1addRevokedCertificates(JNIEnv* env, jobject obj, jlongArray _references)
{
	std::vector<RevokedCertificate> revokedCertificates = Util::getObjectVector<RevokedCertificate>(env, _references);
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	try
	{
		builder->addRevokedCertificates(revokedCertificates);
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
	}
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setNextUpdate(JNIEnv* env, jobject obj, jstring _dateTimeString)
{
	std::string dateTimeString = Util::jstringToString(env, _dateTimeString);
	DateTime dateTime(dateTimeString);
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	builder->setNextUpdate(dateTime);
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setLastUpdate(JNIEnv* env, jobject obj, jstring _dateTimeString)
{
	std::string dateTimeString = Util::jstringToString(env, _dateTimeString);
	DateTime dateTime(dateTimeString);
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	builder->setLastUpdate(dateTime);
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setSerialNumber__Ljava_lang_String_2(JNIEnv* env, jobject obj, jstring _serialNumberString)
{
	std::string serialNumberString = Util::jstringToString(env, _serialNumberString);
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	try
	{
		BigInteger serialNumber(serialNumberString);
		builder->setSerialNumber(serialNumber);
	}
	catch(BigIntegerException& ex)
	{
		Util::throwNewException(env, "BigIntegerException", ex.getMessage());
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
	}
}
void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setSerialNumber__J(JNIEnv* env, jobject obj, jlong _serialNumber)
{
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	try
	{
		builder->setSerialNumber(_serialNumber);
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
	}
}
void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1setVersion(JNIEnv* env, jobject obj, jlong _version)
{
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);
	builder->setVersion(_version);
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1addExtension(JNIEnv* env, jobject obj, jstring _oid, jboolean _isCritical, jbyteArray _value)
{
        std::string oid = Util::jstringToString(env, _oid);
        bool isCritical = (bool)_isCritical;
        ByteArray value = Util::jbytearrayToByteArray(env, _value);

        CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);

        try
        {
                Extension ext(oid, isCritical, Base64::encode(value));
                builder->addExtension(ext);
        }
        catch(CertificationException& ex)
        {
                Util::throwNewException(env, "CertificationException", ex.getMessage());
        }

}

jlong Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1sign(JNIEnv *env, jobject obj, jlong _privateKeyReferenece, jstring _messageDigestAlgorithmString)
{
	std::string messageDigestAlgorithmString = Util::jstringToString(env, _messageDigestAlgorithmString);
	MessageDigest::Algorithm messageDigestAlgorithm = Util::stringToMessageDigestAlgorithm(messageDigestAlgorithmString);
	PrivateKey* privateKey = (PrivateKey*)_privateKeyReferenece;
	CertificateRevocationListBuilder* builder = certInstance;//Util::getInstance<CertificateRevocationListBuilder*>(env, obj);

	try{
		CertificateRevocationList* crl = builder->sign(*privateKey, messageDigestAlgorithm);
		return (jlong)crl;
	}
	catch(CertificationException& ex)
	{
		Util::throwNewException(env, "CertificationException", ex.getMessage());
		return 0;
	}
}

void Java_br_ufsc_labsec_libcryptosec_crl_OpensslCertificateRevocationListBuilder__1delete(JNIEnv *env, jobject obj)
{
	Util::deleteInstance<CertificateRevocationListBuilder*>(env, obj);
}