#include "keys/keys_OpenSSLKeyPair.h"
#include <jni.h>
#include <libcryptosec/KeyPair.h>
#include <libcryptosec/DynamicEngine.h>
#include "util/Util.h"

KeyPair* getInstance(JNIEnv* env, jobject obj)
{
	jclass obj_class = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(obj_class, "reference", "I");
	void* keyPairReference = (void*)env->GetIntField(obj, fid);
	return (KeyPair*) keyPairReference;
}

JNIEXPORT jint JNICALL Java_keys_OpenSSLKeyPair__1loadKeyPair(JNIEnv* env, jobject obj, jint _engineReference, jstring _keyId)
{
	std::string keyId(env->GetStringUTFChars(_keyId, 0));
	DynamicEngine* engine = (DynamicEngine*)_engineReference;

	try
	{
		KeyPair* kp = new KeyPair(engine, keyId);
		return (jint)kp;
	}
	catch(EngineException& ex)
	{
		Util::throwNewException(env, "EngineException", ex.getMessage());
		return 0;
	}

}

JNIEXPORT jint JNICALL Java_keys_OpenSSLKeyPair__1getPublicKey(JNIEnv* env, jobject obj)
{
	try
	{
		return (jint)Util::getInstance<KeyPair*>(env, obj)->getPublicKey();
	}
	catch(AsymmetricKeyException& ex)
	{
		Util::throwNewException(env, "AsymmetricKeyException", ex.getMessage());
		return 0;
	}
	catch(EncodeException& ex)
	{
		Util::throwNewException(env, "EncodeException", ex.getMessage());
		return 0;
	}
}

JNIEXPORT jint JNICALL Java_keys_OpenSSLKeyPair__1getPrivateKey(JNIEnv* env, jobject obj)
{
	try
	{
		return (jint)Util::getInstance<KeyPair*>(env, obj)->getPrivateKey();
	}
	catch(AsymmetricKeyException& ex)
	{
		Util::throwNewException(env, "AsymmetricKeyException", ex.getMessage());
		return 0;
	}
	catch(EncodeException& ex)
	{
		Util::throwNewException(env, "EncodeException", ex.getMessage());
		return 0;
	}
}

JNIEXPORT void JNICALL Java_keys_OpenSSLKeyPair__1delete(JNIEnv* env, jobject obj)
{
	Util::deleteInstance<KeyPair*>(env, obj);
}
