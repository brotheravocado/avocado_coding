package com.example.darktour_project;

import android.Manifest;
import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.GeolocationPermissions;
import android.webkit.JavascriptInterface;
import android.webkit.JsResult;
import android.webkit.WebChromeClient;
import android.webkit.WebResourceRequest;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import android.widget.Toast;
import static com.kakao.kakaonavi.KakaoNaviService.*;
import android.content.pm.PackageManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.Signature;
import android.net.Uri;
import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.widget.Toast;

import com.kakao.kakaonavi.Destination;
import com.kakao.kakaonavi.KakaoNaviParams;
import com.kakao.kakaonavi.KakaoNaviService;
import com.kakao.kakaonavi.Location;
import com.kakao.kakaonavi.NaviOptions;
import com.kakao.kakaonavi.options.CoordType;
import com.kakao.kakaonavi.options.RpOption;
import com.kakao.kakaonavi.options.VehicleType;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.net.URL;
import java.net.URLConnection;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;






import androidx.annotation.Nullable;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import net.daum.mf.map.api.MapPOIItem;
import net.daum.mf.map.api.MapPoint;

import org.json.JSONArray;
import org.json.JSONObject;

public class CarFrag extends Fragment {
    String[] titleNumArr; // 유적지 이름 저장 arr
    ArrayList<String> x = new ArrayList<String>();; // 경도 -lon
    ArrayList<String> y = new ArrayList<String>();; // 위도 -lat
    int[] start_finish_arr; // 시작 도착지 좌표
    private int position = -1;
    View view;
    private Context context;
    private WebView mWebView; // 웹뷰 선언
    private WebSettings mWebSettings; //웹뷰세팅
    private WebSettings mWebSettings_2; //웹뷰세팅
    private volatile WebChromeClient mWebChromeClient;
    private static final int MY_PERMISSION_REQUEST_LOCATION = 0;
    public ArrayList<MyLocationData> locationarray = new ArrayList<>();


    @Nullable
    @Override

    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.carfrag_layout, container, false);
        context = container.getContext();
        Bundle bundle = getArguments();  //번들 받기. getArguments() 메소드로 받음.

        if(bundle != null){
            titleNumArr = bundle.getStringArray("title"); //유적지 이름

            Collections.addAll(x,bundle.getStringArray("x"));
            Collections.addAll(y,bundle.getStringArray("y"));
            start_finish_arr = bundle.getIntArray("start_finish_arr"); //start_finish_arr
        }


        getAppKeyHash();

        mWebView = view.findViewById(R.id.webView);
        if (ContextCompat.checkSelfPermission(getContext(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED){ //Manifest.permission.ACCESS_FINE_LOCATION 접근 승낙 상태 일때
        }
        else{ //Manifest.permission.ACCESS_FINE_LOCATION 접근 거절 상태 일때
            // 사용자에게 접근권한 설정을 요구하는 다이얼로그를 띄운다.
            ActivityCompat.requestPermissions(getActivity()
                    ,new String[]{Manifest.permission.ACCESS_FINE_LOCATION},MY_PERMISSION_REQUEST_LOCATION); }
        set_location();


        mWebSettings = mWebView.getSettings(); //세부 세팅 등록
        mWebSettings.setJavaScriptEnabled(true);
        mWebSettings.setSupportMultipleWindows(false); // 새창 띄우기 허용 여부
        mWebSettings.setAllowFileAccess(true);
        mWebSettings.setGeolocationEnabled(true);
        mWebSettings.setUseWideViewPort(true); // 화면 사이즈 맞추기 허용 여부
        mWebSettings.setLayoutAlgorithm(WebSettings.LayoutAlgorithm.SINGLE_COLUMN); // 컨텐츠 사이즈 맞추기
        mWebSettings.setCacheMode(WebSettings.LOAD_NO_CACHE);
        // Bridge 인스턴스 등록
        mWebView.setWebChromeClient(new WebChromeClient(){
            @Override
            public void onGeolocationPermissionsShowPrompt(String origin, GeolocationPermissions.Callback callback) {
                super.onGeolocationPermissionsShowPrompt(origin, callback);
                callback.invoke(origin, true, false);
            }
        });






        mWebView.loadUrl("http://ip/kakaonavi.html");
        //https://map.kakao.com/?map_type=TYPE_MAP&target=car&rt=494309.0,1128833.0,495527.0,1125478.0,490222.0,1131038.0,497657.0,1126909.0&rt1=덕수궁중명전&rt2=안중근의사기념관&rt3=서대문형무소역사관&rt4=통감관저터
        mWebView.setWebViewClient(new MyWebViewClient());


        return view;
    }
    private class MyWebViewClient extends WebViewClient {
        public static final String INTENT_PROTOCOL_START = "intent:";
        public static final String INTENT_PROTOCOL_INTENT = "#Intent;";
        public static final String INTENT_PROTOCOL_END = ";end;";
        public static final String GOOGLE_PLAY_STORE_PREFIX = "market://details?id=";


        public void onPageFinished(WebView view,String url) {

            mWebSettings_2 = view.getSettings(); //세부 세팅 등록
            mWebSettings_2.setJavaScriptEnabled(true);
            mWebSettings_2.setAllowFileAccess(true);
            mWebSettings_2.setUseWideViewPort(true); // 화면 사이즈 맞추기 허용 여부
            mWebSettings_2.setLayoutAlgorithm(WebSettings.LayoutAlgorithm.SINGLE_COLUMN); // 컨텐츠 사이즈 맞추기
            mWebSettings_2.setCacheMode(WebSettings.LOAD_NO_CACHE);
            mWebSettings_2.setDomStorageEnabled(true); // 로컬저장소 허용 여부
            mWebSettings_2.setGeolocationEnabled(true);
            mWebSettings_2.setSupportMultipleWindows(true); // 새창 띄우기 허용 여부
            set_location();

            if (titleNumArr.length == 2) {
                mWebView.loadUrl("javascript:navi_no('" + locationarray.get(0).getName() + "','" + locationarray.get(0).getLon() + "','" + locationarray.get(0).getLat() + "'" +
                        ",'" + locationarray.get(1).getLon() + "','" + locationarray.get(1).getLat() + "')");
            } else if (titleNumArr.length == 3) {
                mWebView.loadUrl("javascript:navi_one('" + locationarray.get(0).getName() + "','" + locationarray.get(0).getLon() + "','" + locationarray.get(0).getLat() + "'" +
                        ",'" + locationarray.get(1).getLon() + "','" + locationarray.get(1).getLat() + "','" + locationarray.get(2).getName() + "','" + locationarray.get(2).getLon() + "','" + locationarray.get(2).getLat() + "')");

            } else if (titleNumArr.length == 4) {
                mWebView.loadUrl("javascript:navi_two('" + locationarray.get(0).getName() + "','" + locationarray.get(0).getLon() + "','" + locationarray.get(0).getLat() + "'" +
                        ",'" + locationarray.get(1).getLon() + "','" + locationarray.get(1).getLat() + "','" + locationarray.get(2).getLon() + "','" + locationarray.get(2).getLat() + "'" +
                        ",'" + locationarray.get(3).getName() + "','" + locationarray.get(3).getLon() + "','" + locationarray.get(3).getLat() + "')");
            } else if (titleNumArr.length == 5) {

                mWebView.loadUrl("javascript:navi_three('" + locationarray.get(0).getName() + "','" + locationarray.get(0).getLon() + "','" + locationarray.get(0).getLat() + "'" +
                        ",'" + locationarray.get(1).getLon() + "','" + locationarray.get(1).getLat() + "','" + locationarray.get(2).getLon() + "','" + locationarray.get(2).getLat() + "'" +
                        ",'" + locationarray.get(3).getLon() + "','" + locationarray.get(3).getLat() + "','" + locationarray.get(4).getName() + "','" + locationarray.get(4).getLon() + "','" + locationarray.get(4).getLat() + "')");
            }
        }

        @Override
        public boolean shouldOverrideUrlLoading(WebView view, WebResourceRequest request) {
            String url = request.getUrl().toString();
            mWebSettings_2 = view.getSettings(); //세부 세팅 등록
            mWebSettings_2.setJavaScriptEnabled(true);
            mWebSettings_2.setAllowFileAccess(true);
            mWebSettings_2.setUseWideViewPort(true); // 화면 사이즈 맞추기 허용 여부
            mWebSettings_2.setLayoutAlgorithm(WebSettings.LayoutAlgorithm.SINGLE_COLUMN); // 컨텐츠 사이즈 맞추기
            mWebSettings_2.setCacheMode(WebSettings.LOAD_NO_CACHE);
            mWebSettings_2.setDomStorageEnabled(true); // 로컬저장소 허용 여부
            mWebSettings_2.setGeolocationEnabled(true);

            if (url.startsWith(INTENT_PROTOCOL_START)) {
                final int customUrlStartIndex = INTENT_PROTOCOL_START.length();
                final int customUrlEndIndex = url.indexOf(INTENT_PROTOCOL_INTENT);
                if (customUrlEndIndex < 0) {
                    return false;
                } else {
                    final String customUrl = url.substring(customUrlStartIndex, customUrlEndIndex);
                    try {
                        getContext().startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse(customUrl)));
                    } catch (ActivityNotFoundException e) {
                        final int packageStartIndex = customUrlEndIndex + INTENT_PROTOCOL_INTENT.length();
                        final int packageEndIndex = url.indexOf(INTENT_PROTOCOL_END);
                        final String packageName = url.substring(packageStartIndex, packageEndIndex < 0 ? url.length() : packageEndIndex);

                        int idx = customUrl.indexOf("?");
                        String string_back = customUrl.substring(idx+1);

                        String realUrl = ("https://kakaonavi-wguide.kakao.com/navigate.html?"+string_back);
                        Log.d("아잉2", realUrl);
                        view.loadUrl(String.valueOf(Uri.parse(realUrl)));
                    }
                    return true;
                }
            } else {
                return false;
            }


        }

    }
    public class MyLocationData { // locationdata 저장 클래스
        private String name;
        private String lon;
        private String lat;

        public MyLocationData(String name,String lon,String lat){
            this.name = name;
            this.lon = lon;
            this.lat = lat;

        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getLon() {
            return lon;
        }

        public void setLon(String lon) {
            this.lon = lon;
        }

        public String getLat() {
            return lat;
        }

        public void setLat(String lat) {
            this.lat = lat;
        }


    }
    private void set_location(){

        locationarray.add(new MyLocationData(titleNumArr[start_finish_arr[1]],x.get(start_finish_arr[1]),y.get(start_finish_arr[1])));
        for(int i =0; i < titleNumArr.length; i++){
            if(!(x.get(i).equals(x.get(start_finish_arr[0]))) && !(x.get(i).equals(x.get(start_finish_arr[1])))){
                locationarray.add(new MyLocationData(titleNumArr[i],x.get(i),y.get(i)));
            }
        }
        locationarray.add(new MyLocationData(titleNumArr[start_finish_arr[0]],x.get(start_finish_arr[0]),y.get(start_finish_arr[0])));








    }
    private void getAppKeyHash() {
        try {
            PackageInfo info = context.getPackageManager().getPackageInfo(context.getPackageName(), PackageManager.GET_SIGNATURES);
            for (Signature signature : info.signatures) {
                MessageDigest md;
                md = MessageDigest.getInstance("SHA");
                md.update(signature.toByteArray());
                String something = new String(Base64.encode(md.digest(), 0));
                Log.e("Hash key", something);
            }
        } catch (Exception e) {
// TODO Auto-generated catch block
            Log.e("name not found", e.toString());
        }
    }

}